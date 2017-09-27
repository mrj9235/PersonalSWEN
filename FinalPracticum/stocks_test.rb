require_relative 'stocks_util' 
require 'test/unit'          

class StocksTest < Test::Unit::TestCase 

	def test_parse_line
		assert_equal %w{GOOG 10}, parse_line("GOOG,10")
		assert_equal %w{GOOG 10 FB}, parse_line("GOOG,10,FB")
	end

	# assert_in_delta() is used to compare two floating point
	# values within a tolerance, or delta to account for potential
	# rounding errors when performing floating point computations.

	def test_market_value
		assert_in_delta 5389.5, market_value( 'GOOG', 10  ), 0.01
	end

	def test_compute_exchange
		assert_in_delta 67.46, compute_exchange( 'GOOG', 10, 'FB' ), 0.01
	end

	#ADD YOUR TESTS BELOW
	#BEGIN_STUDENT

	def test_line
		assert_equal %w{FB 10}, parse_line("FB,10")
	end





	#END_STUDENT
end
