<?php 


?>
<div>
	<div id="wrapper">
    	<div class="row">
		
        
        <div class="row_left_col">

<!--
	"i"=>"0", // ID
	"l"=>"<no label>", // Label
	"c"=>0.0, // container volume
	"f"=>70.0, // target fill level in percentage
	"t"=>1.0, // fill rate in units /sec 
	"o"=>2.0, // fill tolerance in +/- percentage points 
	"t"=>17.0, // Initial Temp in Celsius
	"g"=>80.0, // Target Temperature in Celsius
	"s"=>0.5, // Temperature change rate in Celsius /sec
	"q"=>1.0, // Temperature Target Tolerance +/- percentage
	"p"=>101.325, // Initial Pressure in kPa
	"k"=>5, // Rate of pressure change in kPa /sec
	"m"=>200.0, // Maximum Pressure in kPa
	"h"=>7.0 // Initla Ph 
    -->    
        <div id="form">
            
                <div class="row">
                    <div class="row_left_col">
                        <h3>BioReactor</h3> 
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <form id="bioMenu" name="bioMenu" method="post" action="index.php">
                    	<input type="hidden" id="id" name="id" value="<?=$id?>">
                       <input type="hidden" id="menu" name="menu" value="new">
                       <input name="label" type="text" id="label" value="myBioReactor" size="10" maxlength="20" /> <input type="submit" value="Create">
                    </form>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <h3>&nbsp;</h3> 
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <form id="bioMenu" name="bioMenu" method="post" action="index.php">
                    	<input type="hidden" id="id" name="id" value="<?=$id?>">
                       <input type="hidden" id="menu" name="menu" value="find">
                       <input name="bioStatus" type="text" id="id" value="" size="10" maxlength="20" /> <input type="submit" value="Status">
                    </form>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                <div class="row">
                    <div class="row_left_col">
                        <h3>&nbsp;</h3> 
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <form id="bioMenu" name="bioMenu" method="post" action="index.php">
                    	<input type="hidden" id="id" name="id" value="<?=$id?>">
                       <input type="hidden" id="menu" name="menu" value="report">
                       <input name="bioReport" type="text" id="id" value="" size="10" maxlength="20" /> <input type="submit" value="Report">
                    </form>
                    </div><!-- row_right_col -->
                </div><!-- row -->
               
        </div><!-- form -->
        </div>
        <div class="row_right_col">
           <div id="image">	
                <img src="images/droplet.jpg" width="467" height="249" />
                <p>&copy; Copyright 2021</p>
          </div>
        </div><!-- row_right_col -->
        
        </div>
    </div><!-- wrapper -->
</div>
<!-- end new -->