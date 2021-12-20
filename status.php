<?php ?>
<div>
	<div id="wrapper">
    	<div class="row">
		
        
        <div class="row_left_col">
        <div id="form">
            
                <div class="row">
                    <div class="row_left_col">
                        <h3><?=$statusArray['Label']?> id=<?= $id ?></h3>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    	<form id="refresh" name="refresh" method="post" action="index.php">
                     		<input type="hidden" id="id" name="id" value="<?=$id?>">
                            <input type="hidden" id="menu" name="menu" value="status">
                            <input type="submit" value="Refresh">
                        </form>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Status</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <?
					if ( $statusArray['Status'] == 'ERRORED' ) {
						$errorStyle = '<error>'.$statusArray['Status'].'</error>';
					} else {
						$errorStyle = '<running>'.$statusArray['Status'].'</running>';
					}
					?>
                        <p><?=$errorStyle?></p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Current Fill Level:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p><?=$statusArray['FillLevelPercentage']?>%</p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Current PH:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p><?=$statusArray['Ph']?></p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Current Temperature:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p><?=$statusArray['Temperature']?> C</p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Current Pressure:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p><?=$statusArray['Pressure']?> kPa</p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Input Valve:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <?
					if ( $configArray['InputValveOpen'] == 0 ){
						// Valve Currently Open
						$inputValveStatus = "Closed";
						$inputButtonLabel = "Open";
						$inputValveState = 1;
					} else {
						// Valve Currently Closed
						$inputValveStatus = "Open";
						$inputButtonLabel = "Close";
						$inputValveState = 0;
					}
					?>
                        <p><?=$inputValveStatus?></p>
                        <form id="inputValve" name="inputValve" method="post" action="index.php">
                     		<input type="hidden" id="id" name="id" value="<?=$id?>">
                            <input type="hidden" id="menu" name="menu" value="status">
                            <input type="hidden" id="InputValveOpen" name="InputValveOpen" value="<?=$inputValveState?>">
                            <input type="submit" value="<?=$inputButtonLabel?>">
                        </form>                      
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Output Valve:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <?
					if ( $configArray['OutputValveOpen'] == 0 ){
						// Valve Currently Open
						$outputValveStatus = "Closed";
						$outputButtonLabel = "Open";
						$outputValveState = 1;
					} else {
						// Valve Currently Closed
						$outputValveStatus = "Open";
						$outputButtonLabel = "Close";
						$outputValveState = 0;
					}
					?>
                        <p><?=$outputValveStatus?></p>
                        <form id="outputValve" name="outputValve" method="post" action="index.php">
                     		<input type="hidden" id="id" name="id" value="<?=$id?>">
                            <input type="hidden" id="menu" name="menu" value="status">
                            <input type="hidden" id="OutputValveOpen" name="OutputValveOpen" value="<?=$outputValveState?>">
                            <input type="submit" value="<?=$outputButtonLabel?>">
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