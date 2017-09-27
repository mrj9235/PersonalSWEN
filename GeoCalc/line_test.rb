require_relative 'line'
require 'test/unit'

class LineTest < Test::Unit::TestCase

	def test_line
		p1 = Point.new(3, 0)
		p2 = Point.new(6, 0)
		l = Line.new(p1, p2)
		assert_equal 3, l.length, "the length should be 3"
	end
	def test_negative
		p1 = Point.new(-3, 6)
		p2 = Point.new(4, 1)
		l = Line.new(p1, p2)
		assert_equal 8.602325267042627, l.length, "the length should be 8.602325267042627"
	end
	
	def test_decimals
		p1 = Point.new(2.5, 1)
		p2 = Point.new(5.5, 1)
		l = Line.new(p1, p2)
		assert_equal 3, l.length, "the length should be 3"
	end
end
