require_relative 'BasicFood'

class Recipe
  ##initialize new recipe
  def initialize(name)
    @name = name
    @foods = Array.new()
  end

  attr_reader :name,  :foods

  ##formats the recipe to a proper string
  def to_s()
    calories = 0
    @foods.each do |food|
      ##counts the number of calories total in the recipe
      calories += food.calories.to_i
    end
    str = "#{@name} #{calories}\n"
    @foods.each do |food|
      str += "  " + food.to_s + "\n"
    end
    return str
  end

end
