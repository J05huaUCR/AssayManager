<?php ?>
<div>
	<div id="wrapper">
    	<div class="row">
		
        
        <div class="row_left_col">
        <div id="form">
            
                <div class="row">
                    <div class="row_left_col">
                        <h3><?=$reportArray['Label']?> id=<?= $id ?></h3>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    	<p>
							<?=$reportArray['TotalTime']?> seconds
                        </p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Status</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                    <?
					if ( $statusArray['Successful'] == 'ERRORED' ) {
						$errorStyle = '<error>'.$reportArray['Successful'].'</error>';
					} else {
						$errorStyle = '<running>'.$reportArray['Successful'].'</running>';
					}
					?>
                        <p><?=$errorStyle?></p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Final Fill Level:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p></p>
                        <p>
							<?=$reportArray['FillLevel']?>%
                            <?
								if ( $reportArray['VolumeState'] == 'OK' ) {
									$errorStyle = '<running>'.$reportArray['VolumeState'].'</running>';
								} else {
									$errorStyle = '<error>'.$reportArray['VolumeState'].'</error>';
								}
							?> 
                            <?=$errorStyle?>
                        </p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Temperature range:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p>
							<?=$reportArray['TempMin']?> - <?=$reportArray['TempMax']?> C
                            <?
								if ( $reportArray['TemperatureState'] == 'OK' ) {
									$errorStyle = '<running>'.$reportArray['TemperatureState'].'</running>';
								} else {
									$errorStyle = '<error>'.$reportArray['TemperatureState'].'</error>';
								}
							?> 
                            <?=$errorStyle?>
                        </p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>Pressure range:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p>
							<?=$reportArray['PressureMin']?> - <?=$reportArray['PressureMax']?> C
                            <?
								if ( $reportArray['PressureState'] == 'OK' ) {
									$errorStyle = '<running>'.$reportArray['PressureState'].'</running>';
								} else {
									$errorStyle = '<error>'.$reportArray['PressureState'].'</error>';
								}
							?> 
                            <?=$errorStyle?>
                        </p>
                    </div><!-- row_right_col -->
                </div><!-- row -->
                
                <div class="row">
                    <div class="row_left_col">
                        <p>PH range:</p>
                    </div><!-- row_left_col --> 
                    <div class="row_right_col">
                        <p>
							<?=$reportArray['PhMin']?> - <?=$reportArray['PhMax']?>
                        </p>
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