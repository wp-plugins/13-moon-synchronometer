<?php // get_ns_date.inc -- solely to get the proper NS date for the kin page
	
$mp_thisfile[] = "get_ns_date.inc";  // get_ns_date CALLED BY: settings_dates.inc

// Build the calendar

// Decode the requested Gregorian date: returns: $hilite_kin_num
// $hilite_kin_num = tmc_date_mysql_to_kin($mysql_date, $dcode_bcad);

// WE HAVE ALL WE NEED TO CREATE THE 13-MOON SOLAR CYCLE =====================
// Make a function that creates an array of dates & moons for every day of the 13-moon solar cycle - given a MySQL date
// Here's our magic code... it returns an array with 364 items
// starting with:             [0] => 1--1--1--2009-7-26
// ending with:             [363] => 364--28--13--2010-7-24
// Call the new array
$array_moons_dates = ms_date_moon_array($dcode_mo, $dcode_day, $dcode_yr);

// Set start moon, in order to correct error... on dates from Jul 27 - Aug 22
$this_moon_num = 1;

/*
$dcode_yr 	= adodb_date("Y");
$dcode_mo 	= adodb_date("n");
$dcode_day 	= adodb_date("j");


if ((isset($_GET['dcode_yr']))&&(isset($_GET['dcode_yr']))&&(isset($_GET['dcode_yr']))){
// Assign GET to vars
	$dcode_yr 	= $_GET['dcode_yr'];
	$dcode_mo 	= ltrim($_GET['dcode_mo'], '0');
	$dcode_day 	= ltrim($_GET['dcode_day'], '0');
}



$dcode_bcad 	= "AD";

*/

$comp_mysql_date = "$dcode_yr-$dcode_mo-$dcode_day";

// Loop through array of months to get this moon number, and next moon's beginning date
foreach ($array_moons_dates as $moon_date_item){
	foreach ($moon_date_item as $moon_date){
		$exploded_moon_date = explode("--", $moon_date);

// Get this day's moon number
//		$matching[] = "$mysql_date::$moon_date";

		if ($exploded_moon_date[1] == "$comp_mysql_date"){
			$this_moon_num = $exploded_moon_date[0];
		}
// Find next month's first day
		if ((($this_moon_num + 1) == $exploded_moon_date[0])&&($this_moon_num !== "13")){
			$next_moon_first_day = $exploded_moon_date[1];
			$exploded_next_moon_first_day = explode("-", $next_moon_first_day);
			$next_moon_first_yr  = $exploded_next_moon_first_day[0];
			$next_moon_first_mo  = $exploded_next_moon_first_day[1];
			$next_moon_first_day = $exploded_next_moon_first_day[2];
		}
// Check to see if we need to increment year for next month
		if ($this_moon_num === "13"){
			$next_moon_first_yr  = $dcode_yr;
			$next_moon_first_mo  = 7;
			$next_moon_first_day = 26;
			break;
		}
	}
}


// Loop through again to get LAST month
foreach ($array_moons_dates as $moon_date_item_lm_s){
	foreach ($moon_date_item_lm_s as $moon_date_lm){
		$exploded_moon_date_lm = explode("--", $moon_date_lm);
// Find last month's first day
		if (($this_moon_num - 1) == $exploded_moon_date_lm[0]){
			$last_moon_first_day = $exploded_moon_date_lm[1];
			$exploded_last_moon_first_day = explode("-", $last_moon_first_day);
			$last_moon_first_yr  = $exploded_last_moon_first_day[0];
			$last_moon_first_mo  = $exploded_last_moon_first_day[1];
			$last_moon_first_day = $exploded_last_moon_first_day[2];
			break;
		}
// Check to see if we need to increment year for next month
		if ($this_moon_num === "1"){
			$last_moon_first_yr  = $dcode_yr;
			$last_moon_first_mo  = 6;
			$last_moon_first_day = 27;
			break;
		}
	}
}

// Rows and cols of calendar table
// Loop through array of months
$show_blank_cell = "Y";
$day_count = 1;
$day_of_mo_num = 1;
$wk_count = 1;
$loop_moon = 1;

foreach ($array_moons_dates[$this_moon_num] as $moon_date_item){

	$exploded_moon_date = explode("--", $moon_date_item);
	$this_ns_mysql_date = $exploded_moon_date[1];

// Break up date for functions
	$this_date_pcs = explode("-", $this_ns_mysql_date);

// Create new row
	if (($day_count === 8)||($day_count === 15)||($day_count === 22)){
		$wk_count++;
	}


// CREATE THE CELL FOR THE DAY ====================================
// This is the day requested... store it

	$todays_comp_date = "$dcode_yr-$dcode_mo-$dcode_day";

	if ($this_ns_mysql_date == $todays_comp_date){
		$ns_month_day = $this_moon_num.".".$day_count;
	}
	
// Increment to next year for DOOT 0.0	

// Finished creating cell for the day =============================
	$day_count++;
	$day_of_mo_num++;
}



// Asking for DOOT July 25 -- We simply need to get the proper cycles
if (($dcode_mo === "7") && ($dcode_day === "25")){
	$ns_month_day = "0.0";
	$tmc_yrs_since_array = tmc_ns_yr_nums($dcode_yr, "7", "26"); // returns array of two items: x x
	$tmc_ns_first_cycle = $tmc_yrs_since_array[0];
	$tmc_ns_second_cycle = $tmc_yrs_since_array[1];
	
	// $tmc_ns_first_cycle
	if ($tmc_ns_first_cycle == "-0"){
	      $tmc_ns_first_cycle = str_replace("-", "", "$tmc_ns_first_cycle");
	}
	
	$tm_date_proper = "NS".$tmc_ns_first_cycle.".".$tmc_ns_second_cycle.".".$ns_month_day;
	
} else {

// Use function to get the correct 13moon date
	$tmc_yrs_since_array = tmc_ns_yr_nums($dcode_yr, $dcode_mo, $dcode_day); // returns array of two items: x x
	$tmc_ns_first_cycle = $tmc_yrs_since_array[0];
	$tmc_ns_second_cycle = $tmc_yrs_since_array[1];

// $tmc_ns_first_cycle
	if ($tmc_ns_first_cycle == "-0"){
	      $tmc_ns_first_cycle = str_replace("-", "", "$tmc_ns_first_cycle");
	}

// Create the proper 13-moon date display
	$tm_date_proper = "NS".$tmc_ns_first_cycle.".".$tmc_ns_second_cycle.".".$ns_month_day;
}

?>