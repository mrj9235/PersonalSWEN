require_relative 'Recipe'
require_relative 'BasicFood'
require_relative 'FoodDB'
require_relative 'Log'
require_relative 'LogItem'
require  'date'

##crates a new Food Database
base = FoodDB.new()
##creates a new DietLog
log = Log.new()
##creats a new file to read in to create data base
file = File.new("FoodDB.txt", "r")
##reads throw each line and adds the food or recipe into the data base
while(line = file.gets) do
  line.chomp!
  words = line.split(',')
  if words[1].eql?('b')
    newFood = BasicFood.new(words[0], words[2])
    base.base[words[0].downcase] = newFood
  else
    newRecipe = Recipe.new(words[0])
    i = 2
    while i < words.length
      if base.base.has_key? (words[i].downcase)
        newRecipe.foods.insert(newRecipe.foods.length, base.base[words[i].downcase])
      else
        break;
      end
      i += 1
    end
    if i == words.length
      base.base[newRecipe.name.downcase] = newRecipe
    end
  end
end
file.close

##creates new file to set up DietLog
file = File.new("DietLog.txt", "r")
while(line = file.gets) do
  line.chomp!
  words = line.split(',')
  date = Date.strptime(words[0], '%m/%d/%Y')
  if log.log.has_key? date
    log.log[date] += [LogItem.new(words[1], date)]
  else
    log.log[date] = [LogItem.new(words[1],date)]
  end
end
file.close

##variables to see if either database or the log have had things added to or removed from
modified = false
modifiedLog = false
puts "Welcome to the Diet Manager"
$stdin.each do |line|
  line.chomp!
  ##sees if the user inputed quit, will save if the files have been modified, breaks out of loop
  if line == "quit"
    if modified == true
      base.save()
    end
    if modifiedLog == true
      log.save()
    end
    break

  ##calls the base's print all function
  elsif line.start_with?("print all")
    base.printAll()

  ##prints the single food item or an error message
  elsif line.start_with?("print")
    line.downcase!
    if base.base.has_key?(line[6..line.length])
      puts base.base[line[6..line.length]].to_s()
    else
      puts "Food Data Base does not contain #{line[6..line.length]}"
    end

  ##calls the base's find funtion in FoodDB
  elsif line.start_with?("find")
    words = line.split(" ")
    base.find(words[1])

  ##changes modified to true, creates a new food and calls the addFood method
  elsif line.start_with?("new food")
    modified = true
    words = line[9..line.length]
    food = words.split(',')
    newFood = BasicFood.new(food[0], food[1])
    base.addFood(newFood)

  ##changes modified to true, creates new recipe and adds each food to the recipe food array
  ##if food doesn't exist, it displays an error message
  ##if all foods exist then it calls the addRecipe method
  elsif line.start_with?("new recipe")
    modified = true
    words = line[11..line.length]
    recipe = words.split(',')
    if base.base.has_key?(recipe[0].downcase)
      puts "Recipe already exists"
    else
      newRecipe = Recipe.new(recipe[0])
      i = 1
      while i < recipe.length do
        if base.base.has_key? (recipe[i].downcase)
          newRecipe.foods.insert(0,  base.base[recipe[i].downcase])
        else
          break;
        end
        i+=1;
      end 
      if i != recipe.length
        puts 'all required foods arent in the DataBase'
      else
        base.addRecipe(newRecipe)
      end
    end

  ##if either log or base is modified, it will call the respective save function
  elsif line.start_with?("save")
    if modified == true
      base.save()
      modified = false
    end
    if modifiedLog == true
      log.save()
      modifiedLog = false
    end

  ##creates a new LogItem with the date the user provides and adds it into the Log
  ##sets modified to true
  elsif line.start_with?('log') && line.include?(',')
    data = line[4..line.length]
    words = data.split(',')
    date = Date.strptime(words[1], '%m/%d/%Y')
    if !base.base.has_key? words[0].downcase
      puts words[0] + ' is not in the data base'
    elsif log.log.has_key? date
      log.log[date] += [LogItem.new(words[0], date)]
    else
      log.log[date] = [LogItem.new(words[0],date)]
    end
    modifiedLog = true


  ##creates a new LogItem with todays date and adds it into the Log
  ##sets modified to true

  elsif line.start_with?('log')
    date = Date.today
    words = line.split(" ")
    if !base.base.has_key? words[1].downcase
      puts words[1] + ' is not in the data base'
    elsif log.log.has_key? date
      log.log[date] += [LogItem.new(words[1],date)]
    else
      log.log[date] = [LogItem.new(words[1],date)]
    end
    modifiedLog = true
  
  ##calls the log's showAll method
  elsif line == 'show all'
    log.showAll()

  ##show without a date shows log events on Today's Date
  ##calls log's show method passing in today's date
  elsif line == 'show'
    date = Date.today
    log.show(date)
  
  ##calling show with a specific date
  ##calls the show method with the specific date the user entered
  elsif line.start_with? 'show'
    d = line[5..line.length]
    date = Date.strptime(d, '%m/%d/%Y')
    log.show(date)

  ##creates date and calls the log's remove function passing in the date and the name
  ##that the user entered
  elsif line.start_with? 'delete'
    d = line[7..line.length]
    data = d.split(',')
    date = Date.strptime(data[1], '%m/%d/%Y')
    log.remove(data[0], date)
    modifiedLog = true
  end
end
