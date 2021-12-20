<?php
// config.php
$BASE_URL = "http://www.binary7design.com/bioreactor/";

/*
// Flag I: ID
// Flag I: Label
// Flag C: Container Volume
// Flag F: Target Volume in percentage
// Flag R: Fill rate in units/sec
// Flag O: FillTarget Tolerance +/- percentage
// Flag T: Initial Temp in Celsius
// Flag G: Target Temperature in Celsius
// Flag S: Temperature change rate in Celsius /sec
// Flag Q: Temperature Target Tolerance +/- percentage
// Flag P: Initial Pressure in kPa
// Flag K: Rate of pressure change in kPa /sec
// Flag M: Maximum Pressure in kPa
// Flag H: Initla Ph

./main.run -i 300 -l bio1 -c 100.0 -f 70 -r 10 -o 2.0 -t 17.5 -g 80.0 -s 0.5 -q 1.0 -p 50.0 -k 3.5 -m 200.0 -h 7.0 
*/
$defaults = array(
	"i"=>"0", // ID
	"l"=>"bioReactor", // Label
	"c"=>50.0, // container volume
	"f"=>70.0, // target fill level in percentage
	"r"=>10.0, // fill rate in units /sec 
	"o"=>2.0, // fill tolerance in +/- percentage points 
	"t"=>17.5, // Initial Temp in Celsius
	"g"=>80.0, // Target Temperature in Celsius
	"s"=>0.5, // Temperature change rate in Celsius /sec
	"q"=>1.0, // Temperature Target Tolerance +/- percentage
	"p"=>101.325, // Initial Pressure in kPa
	"k"=>1.0, // Rate of pressure change in kPa /sec
	"m"=>200, // Maximum Pressure in kPa
	"h"=>7.0 // Inital Ph
	);

?>