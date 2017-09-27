$stdin.each do |line|
	line.chomp!
	puts line.downcase!
	line.gsub(/[^a-zA-Z\s]/)
	line.sub!(/^\s+/, '')
end
