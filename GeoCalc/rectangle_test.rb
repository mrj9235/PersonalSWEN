
require_relative 'rectangle'
require 'test/unit'

class RectangleTest < Test::Unit::TestCase

	def test_width
		c1 = Point.new(2, 3)
		c2 = Point.new(8, 10)
		rect = Rectangle.new(c1, c2)
		assert_equal 6, rect.width, "width should be six"
	end

	def test_height
		c1 = Point.new(2, 3)
                c2 = Point.new(8, 10)
                rect = Rectangle.new(c1, c2)
		assert_equal 7, rect.height, "height should be seven"
	end

	def test_perimeter
		c1 = Point.new(2, 3)
                c2 = Point.new(8, 10)
                rect = Rectangle.new(c1, c2)
		assert_equal 26, rect.perimeter, "perimeter should be 26"
	end

	def test_area
		c1 = Point.new(2, 3)
        	c2 = Point.new(8, 10)
	        rect = Rectangle.new(c1, c2)
		assert_equal 42, rect.area, "area should be 42"
	end 
end
