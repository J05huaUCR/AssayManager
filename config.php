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
*/
$defaults = array(
	"i"=>"0", // ID
	"l"=>"<no label>", // Label
	"c"=>0.0, // container volume
	"f"=>70.0, // target fill level in percentage
	"r"=>1.0, // fill rate in units /sec 
	"o"=>2.0, // fill tolerance in +/- percentage points 
	"t"=>17.0, // Initial Temp in Celsius
	"g"=>80.0, // Target Temperature in Celsius
	"s"=>0.5, // Temperature change rate in Celsius /sec
	"q"=>1.0, // Temperature Target Tolerance +/- percentage
	"p"=>101.325, // Initial Pressure in kPa
	"k"=>5, // Rate of pressure change in kPa /sec
	"m"=>200.0, // Maximum Pressure in kPa
	"h"=>7.0 // Initla Ph
	);
?>