# Stock Exchange Calculator Utility Methods

# Hash of stock values in USD (US Dollars) to be used in calculations
STOCKS = {
	"AAPL" => 129.49,
	"DIS" => 100.00,
	"FB" => 79.89,
	"GOOG" => 538.95,
	"SBUX" => 93.51,
	"TWTR" => 50.00
}

# Given a stock ticker symbol and quantity of shares,
# return the equivalent USD as a floating point value using the STOCKS Hash.
# returns 0.0 if stock ticker symbol does not exist

def market_value( stock_ticker_symbol, shares )
	result = 0.0

	#BEGIN_STUDENT
		if STOCKS.has_key? (stock_ticker_symbol)
			result = (STOCKS.fetch(stock_ticker_symbol) * shares.to_f).round(2)
                end	

	#END_STUDENT

	return result
end

# Based on the market value of the given first stock ticker symbol and shares,
# return the boolean value indicating whether exchange is possible
# Note: You are trying to verify that you can buy the second pair of shares
# 
# If stock ticker unknown or number of shares <= 0 result is false
#
def verify_exchange( stock_ticker_symbol_1, shares_1, stock_ticker_symbol_2, shares_2 )
	result = false
	#BEGIN_STUDENT
	if shares_1.to_i <= 0 || shares_2.to_i <= 0
		return result
	end
	if !STOCKS.has_key?(stock_ticker_symbol_1) && !STOCKS.has_key?(stock_ticker_symbol_2)
		return false
        end
	if market_value(stock_ticker_symbol_1, shares_1) < market_value(stock_ticker_symbol_2,shares_2)
		result = false
        else
		result = true
        end


	#END_STUDENT

	return result
end

# Based on the given first stock ticker symbol and its number of shares,
# computes the market value and then the calculates the equivalent number of 
# shares for the second stock symbol returned as floating point result.
#
# If stock ticker unknown or provided number of shares <= 0 result is 0.0 
#
def compute_exchange( stock_ticker_symbol_1, shares, stock_ticker_symbol_2 )
	result = 0.0

	#BEGIN_STUDENT
	if !STOCKS.has_key?(stock_ticker_symbol_1) || !STOCKS.has_key?(stock_ticker_symbol_2)
		return result
        elsif shares.to_i <= 0
		return result
        else
		v1 = market_value(stock_ticker_symbol_1, shares)
                v2 = STOCKS.fetch(stock_ticker_symbol_2)
                result = (v1 / v2).round(2)
        end

	#END_STUDENT

	return result
end

# Given an input string in CSV format, return an array
# of values.
def parse_line( line )
	line.chomp!
	values = []
	#BEGIN_STUDENT
	words = line.split(',')
        words.each do |word|
		values += [word]
        end
	return values
	#END_STUDENT
end

