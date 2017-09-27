require_relative 'MovieManager.rb'

# Write code that will read in a CSV list of movie ratings (one rating per line)
# that also can contain two different listing commands: LIST and RATINGS
# If the line is exactly LIST display a sorted list of movie names
# If the line is exactly RATINGS display all of the movies (name, rating, and review)
# in a list that is reverse sorted by rating (highest rated entries are listed first).

movielist = MovieList.new

$stdin.each do |line|
  line.chomp!
  
  if line == nil or line.length == 0
	break
  elsif line == 'LIST'
    movienames = movielist.sortByName
	movienames.each do |name|
	  puts name
	end
	
  elsif line == 'RATINGS'
    rated_movie_list = movielist.sortByRating
	rated_movie_list.each do |onemovie|
	  puts onemovie.name + ' ' + onemovie.rating.to_s + ' ' + onemovie.review
	end
	
  else
	csv_entries = line.split(/,/)
	rating = nil
	
	if ( csv_entries[1] != nil )
	  rating = csv_entries[1].to_i
	end
	
    movie = Movie.new( csv_entries[0], rating, csv_entries[2] )
	movielist.add( movie )
  end  
end