select * from Player where position = 2;

select Player.name, Player.age from Player where position = 1 and team = "Rays";

select Player.name, Player.number, Player.team from Player where position <= 9 and  position >=7 and Player.age <= 25;

select Player.name, Player.number from Player where position BETWEEN 3 AND 6 and team = "Red Sox";

select name, number, team from Player where position = 1 and age > 30;
