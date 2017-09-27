require_relative 'LogItem'

class Log
  ##initializes the Log
  def initialize()
    @log = Hash.new()
  end

  attr_reader :log
  ##Prints out each food item for each day
  def showAll()
    dates = []
    @log.each_key do |date|
      dates += [date]
    end
    dates.sort!
    dates.each do |date|
      puts @log[date][0].to_s()
      @log[date].each do |item|
        puts "  " + item.name
      end
    end
  end

  ##shows the foods on a specific day
  def show(date)
    if @log.has_key? date
      @log[date].each do |item|
        puts item.name
      end
    end
  end

  ##saves the data in the log to a textfile
  def save()
    str = ""
      @log.each_key do |date|
        @log[date].each do |item|
          str += item.to_s() + ',' + item.name + "\n"
        end
      end
    File.open("DietLog.txt","w").write(str)
  end

  ##removes a specific item for a specific day
  def remove(name, date)
    if @log.has_key? date
      @log[date].each do |item|
        if name.eql? item.name
          @log[date].delete(item)
        end
      end
    end
    if @log[date].eql? [] ##deletes key if array on date is empty
      @log.delete(date)
    end
  end      

end
