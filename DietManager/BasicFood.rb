class BasicFood

  ##initialize a new basic food
  def initialize(name, calories)
    @name = name
    @calories = calories
  end

  attr_reader :name, :calories
  ##formats the string to print out properly
  def to_s()
    return "#{@name} #{@calories}"
  end

end
