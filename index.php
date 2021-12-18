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
if( isset($_POST['id'] ) ) {
	
	// Check if id present
	$id = $_POST['id'];

	if ( isset($_POST['new'] ) ) {
		
		// creating
		$label = $_POST['label'];
		$json['count'] = $count + 1;
		file_put_contents($dirFileName, json_encode($json));
		
		// Build command path
		$program = "main.run";
		
		// Build paramters
		$paramters  = " -i " . $id;
		$paramters .= " -l " . $label;
		$paramters .= " -c " . $defaults['c'];
		$paramters .= " -f " . $defaults['f'];
		$paramters .= " -r " . $defaults['r'];
		$paramters .= " -o " . $defaults['o'];
		$paramters .= " -t " . $defaults['t'];
		$paramters .= " -g " . $defaults['g'];
		$paramters .= " -s " . $defaults['s'];
		$paramters .= " -q " . $defaults['q'];
		$paramters .= " -p " . $defaults['p'];
		$paramters .= " -k " . $defaults['k'];
		$paramters .= " -m " . $defaults['m'];
		$paramters .= " -h " . $defaults['h'];
		
		//echo "Executable path: " . $program . $paramters . "</br>";
		
		if ( file_exists($program) ) {
			/**/
			$program .= $paramters;
			exec("./". $program . " 2>&1", $output, $return); 

		} else {
			echo $program . " does not exist.</br></br>";
		}
		
	} 
	
	$statusFileName = "reports/".$id."_status.json";
	if ( file_exists($statusFileName) ) {
		$statusArray = json_decode(file_get_contents($statusFileName),TRUE);
		if ( isset($_POST['InputValveOpen'] ) ) {
			$statusArray['InputValveOpen'] = $_POST['InputValveOpen'];
		}
		
		if ( isset($_POST['OutputValveOpen'] ) ) {
			$statusArray['OutputValveOpen'] = $_POST['OutputValveOpen'];
		}
		file_put_contents($statusFileName, json_encode($statusArray));
		
		// viewing /updating status
		foreach ($statusArray as $k => $v ) {
			echo $k;
			echo ": ";
			echo $v;
			echo "<br>";
		}
	} else {
		echo "status file |";	
		echo $statusFileName;
		echo "| does not exist<br>";
	}
	
	$configFileName = "configs/".$id."_config.json";
	if ( file_exists($configFileName) ) {
		$configArray = json_decode(file_get_contents($configFileName),TRUE);
		if ( isset($_POST['InputValveOpen'] ) ) {
			$configArray['InputValveOpen'] = $_POST['InputValveOpen'];
		}
		
		if ( isset($_POST['OutputValveOpen'] ) ) {
			$configArray['OutputValveOpen'] = $_POST['OutputValveOpen'];
		}
		file_put_contents($configFileName, json_encode($configArray));
		
		// viewing /updating status
		foreach ($statusArray as $k => $v ) {
			echo $k;
			echo ": ";
			echo $v;
			echo "<br>";
		}
	} else {
		echo "config file |";	
		echo $configFileName;
		echo "| does not exist<br>";
	}
	
	
	
	
	/*
	if ( file_exists($statusFileName) ) {
		echo $statusFileName . " exists.</br></br>";
	} else {
		echo $statusFileName . " does not exist.</br></br>";
	}
	
	foreach ($statusArray as $k => $v ) {
		echo $k;
		echo ": ";
		echo $v;
		echo "<br>";
	}
	*/

	$menu = 'status';
} else {
	$menu = 'new';
	$id = $count;
}

?>

<? include_once('styles/default/header.php'); ?>

<? include_once('styles/default/'.$menu.'.php'); ?>

<? include_once('styles/default/footer.php'); ?>
