<?php
// index.php v1.0.0
require("config.php");
//require("api.php");
//echo "RESTfulTest<br>";
//echo $BASE_URL;
//echo "<br>";
//echo $_SERVER['REQUEST_URI'];
//echo "<br>";

/*
INTERFACE
bioreactor/0
GET Used to get a bioreactor for use. Returns the <id> of the bioreactor to use.
bioreactor/<id>
GET Returns the current readings for the interior of the vessel of the bioreactor.
 Fill-level – Percentage
 pH
 Pressure – kPa
 Temperature – degrees Celsius
bioreactor/<id>/input-valve
GET Whether the state of the input valve is open or closed.
PUT Used to set the state of the input valve to open or closed.
bioreactor/<id>/output-valve
GET Whether the state of the output valve is open or closed.
PUT Used to set the state an output valve to open or closed.


foreach ($_POST as $k => $v ) {
	echo $k;
	echo ": ";
	echo $v;
	echo "<br>";
}*/

$dirFileName = "directory.json";
$json = json_decode(file_get_contents($dirFileName),TRUE);
$count = $json['count'];

// Check if bioreactor called
if( isset($_POST['menu'] ) ) {
	
	// Check if id present
	$id = $_POST['id'];

	// if new
	if ( $_POST['menu'] == 'new' ) {

		// Increment id
		$id += 1;
		
		// creating
		$label = $_POST['label'];
		
		// Build command path
		$program = "main.run";
		
		// Build paramters
		$paramters  = " -i " . $id;
		$paramters .= " -l " . $label;
		$paramters .= " -c " . number_format($defaults['c'], 6, '.', '');
		$paramters .= " -f " . number_format($defaults['f'], 6, '.', '');
		$paramters .= " -r " . number_format($defaults['r'], 6, '.', '');
		$paramters .= " -o " . number_format($defaults['o'], 6, '.', '');
		$paramters .= " -t " . number_format($defaults['t'], 6, '.', '');
		$paramters .= " -g " . number_format($defaults['g'], 6, '.', '');
		$paramters .= " -s " . number_format($defaults['s'], 6, '.', '');
		$paramters .= " -q " . number_format($defaults['q'], 6, '.', '');
		$paramters .= " -p " . number_format($defaults['p'], 6, '.', '');
		$paramters .= " -k " . number_format($defaults['k'], 6, '.', '');
		$paramters .= " -m " . number_format($defaults['m'], 6, '.', '');
		$paramters .= " -h " . number_format($defaults['h'], 6, '.', '');
		
		if ( file_exists($program) ) {
			/**/
			$program .= $paramters;
			//exec("./". $program . " 2>&1", $output, $return); 
			exec("./". $program . " > /dev/null &");  
			
			//echo $program;
			
			// Wait before continuing
			sleep(1);
			
			
		} else {
			echo $program . " does not exist.</br></br>";
		}
		
		// Update count
		$json['count'] = $id;
		file_put_contents($dirFileName, json_encode($json));
		
	} // done with new
	
	if ( $_POST['menu'] == 'report' ) {

		// get report
		$reportFileName = "reports/".$id."_report.json";
		if ( file_exists($reportFileName) ) {

			// REad status from JSON
			$reportArray = json_decode(file_get_contents($reportFileName),TRUE);
			
		} else {
			echo "status file |";	
			echo $reportFileName;
			echo "| does not exist<br>";
		}
		$menu = 'report';
		
	} else {
		
		// Edit config
		$configFileName = "configs/".$id."_config.json";
		
		if ( file_exists($configFileName) ) {
			
			// Read config file
			$configArray = json_decode(file_get_contents($configFileName),TRUE);
			
			// Set Input Valve
			if ( isset($_POST['InputValveOpen'] ) ) {
				$configArray['InputValveOpen'] = $_POST['InputValveOpen'];
			}
			
			// Set Output Valve
			if ( isset($_POST['OutputValveOpen'] ) ) {
				$configArray['OutputValveOpen'] = $_POST['OutputValveOpen'];
			}
			
			// Write Config File
			file_put_contents($configFileName, json_encode($configArray));

		} else {
			echo "config file |";	
			echo $configFileName;
			echo "| does not exist<br>";
		}
		
		// get status
		$statusFileName = "reports/".$id."_status.json";
		if ( file_exists($statusFileName) ) {
			
			// REad status from JSON
			$statusArray = json_decode(file_get_contents($statusFileName),TRUE);
					
		} else {
			echo "status file |";	
			echo $statusFileName;
			echo "| does not exist<br>";
		}
		
		$menu = 'status';
	}
	
} else {
	$menu = 'new';
	$id = $count;
}

?>

<? include_once('styles/default/header.php'); ?>

<? include_once('styles/default/'.$menu.'.php'); ?>

<? include_once('styles/default/footer.php'); ?>
