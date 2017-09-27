require_relative 'circle'
require 'test/unit'

class CircleTest < Test::Unit::TestCase

	def test_diameter
		center = Point.new(1, 3)
       		on_circle = Point.new(5, 6)
	        circle = Circle.new(center, on_circle)
		assert_equal 10, circle.diameter, "diameter of circle should be ten"
	end

	def test_circumference
		center = Point.new(1, 3)
	        on_circle = Point.new(5, 6)
        	circle = Circle.new(center, on_circle)
		assert_equal 31.41593, circle.circumference, "the circumference should be 10 * pi"
	end

	def test_area
		center = Point.new(1, 3)
	        on_circle = Point.new(5, 6)
        	circle = Circle.new(center, on_circle)
		assert_equal 157.07963, circle.area, "the area should be 157.07963"
	end
end
