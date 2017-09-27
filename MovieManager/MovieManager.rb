# Movie Manager 
# 
# Manages a collection of Movie objects. 
class MovieList
  def initialize
    @movies = Hash.new
    @numberOfMovies = 0    
  end
  
  def size
    @numberOfMovies
  end
  
  def add( movieToAdd )
    @movies.store( movieToAdd.name, movieToAdd)
    @numberOfMovies += 1
  end
  
  def delete( movieToDelete )    
    @movies.delete(movieToDelete.upcase)
  end
  
  def getMovie(movieToFind)    
    @movies.fetch(movieToFind.upcase, nil) 
  end
  
  def sortByName	
     @movies.sort
  end
  
  def sortByRating
    list = @movies.values.sort_by { |x| x.rating }
  end    
    
 end

# Movie Class - Models a movie entry - maintains movie title as an uppercase string,
#               rating (1-10) and text review.
class Movie
  attr_reader :rating
  attr_reader :review
      
  def initialize( aName, aRating=1, aReview="No Review Entered" )
    @name=aName.upcase! 
	self.rating=aRating
    @review=aReview
  end

  def rating=(value)
    if value <=10 || value >=1
      @rating = value
    end
  end
end
