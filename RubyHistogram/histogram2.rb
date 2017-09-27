$stdin.each do |line|
	bag = Hash.new(0)
	words = line.split(/ +/)
	words.each{|word| bag[#{word}] += 1}
	bag.each{|key, value| puts "#{key}: #{value}" }
end
