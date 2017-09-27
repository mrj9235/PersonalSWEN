require_relative 'currency_util' 
require 'test/unit'          

class CurrencyTest < Test::Unit::TestCase 

  def close_enough(expected, actual, epsilon = 0.001)
    return (expected - actual).abs <= epsilon
  end

  ### Tests of to_dollars ###

  def test_001a_convert_3_33_units_to_dollars
    assert close_enough(5.13, to_dollars('GBP', 3.33))
    assert close_enough(2.66, to_dollars('CAN', 3.33))
    assert close_enough(4.26, to_dollars('AUD', 3.33))
    assert close_enough(3.73, to_dollars('EUR', 3.33))
    assert close_enough(3.33, to_dollars('USD', 3.33))
  end

  def test_001b_your_tests
    ## Your set up and assertions here ##
    assert close_enough(50.05, to_dollars('GBP', 32.5))
    assert close_enough(0.40, to_dollars('CAN', 0.5))
    assert close_enough(640, to_dollars('AUD', 500))
    assert close_enough(7.04, to_dollars('EUR', 6.29))
    assert close_enough(68, to_dollars('USD', 68))
  end

  ### Tests of from_dollars ###

  def test_002a_convert_3_33_units_to_dollars
    assert close_enough(2.16, from_dollars('GBP', 3.33))
    assert close_enough(4.16, from_dollars('CAN', 3.33))
    assert close_enough(2.60, from_dollars('AUD', 3.33))
    assert close_enough(2.97, from_dollars('EUR', 3.33))
    assert close_enough(3.33, from_dollars('USD', 3.33))
  end

  def test_002b_your_tests
    ## Your set up and assertions here ##
    assert close_enough(80.94, from_dollars('GBP', 124.65))
    assert close_enough(609.53, from_dollars('CAN', 487.62))
    assert close_enough(9.77, from_dollars('AUD', 12.5))
    assert close_enough(10.40, from_dollars('EUR', 11.65))
    assert close_enough(123.45, from_dollars('USD', 123.45))
  end

  ### Tests of parse ###
  
  def test_003a_normal_line
    expect = ['AUD', '1.56' ,'EUR']
    actual = parse('AUD,1.56,EUR')
    assert_equal(expect, actual)
  end

  def test_003b_your_first_test
    ## Your set up and assertions here ##
    expect = ['USD', '1452.23', 'GBP']
    actual = parse('USD,1452.23,GBP')
    assert_equal(expect, actual)
  end

  def test_003c_your_second_test
    #checking to make sure it works with more than three fields
    expect = ['EUR', '123.12', 'AUD', 'USD']
    actual = parse('EUR,123.12,AUD,USD')
    assert_equal(expect, actual)
  end
end
