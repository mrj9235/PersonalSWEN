require_relative 'Recipe'
require_relative 'BasicFood'

class FoodDB
  ##initializes a new FoodDB
  def initialize()
    @base = Hash.new()
  end

  attr_reader :base
  ##prints every food in the database
  def printAll()
    @base.each_value {|food| puts food.to_s()}
  end

  ##goes through each food and if the food starts with the prefix it gets printed out
  def find(prefix)
    prefix.downcase!
    @base.each_key do |name|
      if name.start_with? prefix
        puts base[name].to_s()
      end
    end
  end

  ##adds a new food into the data base if food is already in the DB
  def addFood(newFood)
    name = newFood.name
    if @base.has_key?(name.downcase)
      puts("Database already contains this food")
    else
      @base[name.downcase] = newFood
    end
  end

  def addRecipe(newRecipe)
    name = newRecipe.name
    @base[name.downcase] = newRecipe
  end

  ##saves each food to a text file
  def save()
    str = ""
      @base.each_value do |item|
        if item.is_a?(BasicFood)
          str += item.name + ",b," + item.calories
        elsif item.is_a?(Recipe)
          str += item.name + ",r"
          item.foods.each do |food|
            str += "," + food.name 
          end
        end
        str += "\n"
      end
    File.open("FoodDB.txt","w").write(str)
  end


end
