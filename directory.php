<?php ?>
<p>Directory</p>
<div class="row">
                    <div class="row_left_col">
                        <h3>BioReactor</h3>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <input type="submit" value="Create!">
<?        
	if ( isset($errors) > 0 || $error_flag ) {
	   echo "<p></p>";
       echo "<div id=\"error\">";
   	   echo " 	<p>ERROR OCCURRED!</p>";
       echo " </div>";
	}
 ?>      
                    </div><!-- row_right_col -->
                </div><!-- row -->