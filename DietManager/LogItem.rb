class LogItem
  ##initializes a new LogItem
  def initialize(name,date)
    @name = name
    @date = date
  end

  attr_reader :name, :date
  ##formats the dates to be in the proper american format
  def to_s()
    str = "" + @date.month.to_s() + "/" + @date.mday.to_s() + "/" + @date.year.to_s()
    return str
  end
end
