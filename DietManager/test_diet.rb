require_relative 'FoodDB'
require_relative 'BasicFood'
require_relative 'Recipe'
require 'test/unit'

class DietTest < Test::Unit::TestCase

  def test_newFood
    food = BasicFood.new('orange', 45)
    assert_equal 'orange', food.name, "Error in getting the name"
  end

  def test_newFood_again
    food = BasicFood.new('orange', 45)
    assert_equal 45, food.calories, "Error in receiving calories"
  end

end
