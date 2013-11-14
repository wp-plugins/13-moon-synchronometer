<?php

// Loop through array of months to get this moon number, and next moon's beginning date
foreach ($array_moons_dates as $moon_date_item){
	foreach ($moon_date_item as $moon_date){
		$exploded_moon_date = explode("--", $moon_date);

// Get this day's moon number
		$matching[] = "$mysql_date::$moon_date";

		if ($exploded_moon_date[1] == "$mysql_date"){
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
?>