
-- CREATE YOUR TABLES HERE

CREATE TABLE Players(
  handle varchar(25)
);

-- DO YOUR INSERTS HERE
INSERT INTO Players VALUES ("kittens27");
INSERT INTO Players VALUES ("thelolcat");
INSERT INTO Players VALUES ("harveykeitel16");
INSERT INTO Players VALUES ("pluto");

-- Write your queries below the print statements
-- Please keep these settings
.echo off
.headers on
.width 25 25 25
.mode column
--

-- All player handles
SELECT Players.handle from Players where Players.handle != null;
-- All game names

-- All guilds and their game, sorted by game name

-- List the Top 3 high scores and players handles for Another Moba, ranked by highest score

-- List all high scores and players handles for Open World Walking, ranked by highest score. Do NOT show any players who do NOT have a high score.

-- List the name, high score, and guild name of guild leaders in Open World Walking, ranked by score

-- List the followers of pluto, alphabetically

-- List the followers of Pluto who also play Open World Walking, alphabetically
