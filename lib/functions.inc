<?php // functions.inc
/* FUNCTIONS IN THIS FILE

tmc_date_mysql_to_kin ($mysql_date, $dcode_bcad)
ms_date_is_leapday
guiding_power
tone_nm_to_img_num
tone_nm_to_img_num_rev
tribe_nm_to_img_num
tmc_date_mysql_to_short
date_mysql_to_very_short
tmc_truncate
tone_name_to_num
tmc_tone_num_to_name
tribe_name_to_num
tribe_num_to_name 
tribe_num_to_color
kin_to_next_gb
kin_to_wavespell
tmc_count_days
num_days_moon_num
ms_moon_start_yr - determine the starting year of the 13m cal from any mysql date
tmc_is_leapyear - advanced method for checking leap year
ms_date_moon_array - creates array of moon illumination of any day/time
class Moon
translate_kin_to_seo ($tran_kin, $database) // Translate URL for SEO
moon_phase ($year, $month, $day) // Gets date of full moon
prof_to_list - Convert list of abbreviated professions to a list of Readable Words
is_portal($kin_ID) - reports past and future portals

tm_day_num_to_plasma_num ($this_day_count) // Used in new calendar
tribe_num_to_tribe_essences_del ($tribe_num)
tone_num_to_tone_essences_del ($tone_num)

tmc_castle_num_to_name($castle_number)

get_this_day_wp_posts($this_mysql_date) // an awesome little func that gets the posts on a given date

*/

// Here's the main decoder
function tmc_date_mysql_to_kin($mysql_date, $dcode_bcad){

	$mysql_date_pcs = explode('-',$mysql_date);
	$birth_yr = $mysql_date_pcs[0];
	$birth_mo = $mysql_date_pcs[1];
	$birth_day = $mysql_date_pcs[2];

	if ($dcode_bcad === "BC"){
			$birth_yr = (($birth_yr) - ($birth_yr * 2));
	}

	if (($birth_yr <> "")&&($birth_mo <> "")&&($birth_day <> "")){

//		if (preg_match("/^[0-9]{1,4}/", $birth_yr)) {
//		    $input_good .= "The year is PROPERLY formatted.<br>";
//		} else {
//			$input_error .= "The year is NOT formatted properly.<br>";
//		}
	
		if ((preg_match("/^[0-9]{1,2}/", $birth_mo))&&($birth_mo < 13)) {
		    $input_good .= "Your birth month is PROPERLY formatted.<br>";
		} else {
			$input_error .= "Your birth month is NOT formatted properly.<br>";
		}
	
		if ((preg_match("/^[0-9]{1,2}/", $birth_day))&&($birth_day < 32)) {
		    $input_good .= "Your birth day is PROPERLY formatted.<br>";
		} else {
			$input_error .= "Your birth day is NOT formatted properly.<br>";
		}
	
		if (isset($input_error)){
			$yr_mo_day_code = "Error: $input_error";
	
		} else {
	
//	 		echo "You Entered the dates: $birth_mo/$birth_day/$birth_yr<p>$input_good <BR> $input_error";
	
			if (($birth_yr - 2013) % 52 == 0){$yr_code = 217;}
			elseif (($birth_yr - 2012) % 52 == 0){$yr_code = 112;}
			elseif (($birth_yr - 2011) % 52 == 0){$yr_code = 7;}
			elseif (($birth_yr - 2010) % 52 == 0){$yr_code = 162;}
			elseif (($birth_yr - 2009) % 52 == 0){$yr_code = 57;}
			elseif (($birth_yr - 2008) % 52 == 0){$yr_code = 212;}
			elseif (($birth_yr - 2007) % 52 == 0){$yr_code = 107;}
			elseif (($birth_yr - 2006) % 52 == 0){$yr_code = 2;}
			elseif (($birth_yr - 2005) % 52 == 0){$yr_code = 157;}
			elseif (($birth_yr - 2004) % 52 == 0){$yr_code = 52;}
			elseif (($birth_yr - 2003) % 52 == 0){$yr_code = 207;}
			elseif (($birth_yr - 2002) % 52 == 0){$yr_code = 102;}
			elseif (($birth_yr - 2001) % 52 == 0){$yr_code = 257;}
			elseif (($birth_yr - 2000) % 52 == 0){$yr_code = 152;}
			elseif (($birth_yr - 1999) % 52 == 0){$yr_code = 47;}
			elseif (($birth_yr - 1998) % 52 == 0){$yr_code = 202;}
			elseif (($birth_yr - 1997) % 52 == 0){$yr_code = 97;}
			elseif (($birth_yr - 1996) % 52 == 0){$yr_code = 252;}
			elseif (($birth_yr - 1995) % 52 == 0){$yr_code = 147;}
			elseif (($birth_yr - 1994) % 52 == 0){$yr_code = 42;}
			elseif (($birth_yr - 1993) % 52 == 0){$yr_code = 197;}
			elseif (($birth_yr - 1992) % 52 == 0){$yr_code = 92;}
			elseif (($birth_yr - 1991) % 52 == 0){$yr_code = 247;}
			elseif (($birth_yr - 1990) % 52 == 0){$yr_code = 142;}
			elseif (($birth_yr - 1989) % 52 == 0){$yr_code = 37;}
			elseif (($birth_yr - 1988) % 52 == 0){$yr_code = 192;}
			elseif (($birth_yr - 1987) % 52 == 0){$yr_code = 87;}
			elseif (($birth_yr - 1986) % 52 == 0){$yr_code = 242;}
			elseif (($birth_yr - 1985) % 52 == 0){$yr_code = 137;}
			elseif (($birth_yr - 1984) % 52 == 0){$yr_code = 32;}
			elseif (($birth_yr - 1983) % 52 == 0){$yr_code = 187;}
			elseif (($birth_yr - 1982) % 52 == 0){$yr_code = 82;}
			elseif (($birth_yr - 1981) % 52 == 0){$yr_code = 237;}
			elseif (($birth_yr - 1980) % 52 == 0){$yr_code = 132;}
			elseif (($birth_yr - 1979) % 52 == 0){$yr_code = 27;}
			elseif (($birth_yr - 1978) % 52 == 0){$yr_code = 182;}
			elseif (($birth_yr - 1977) % 52 == 0){$yr_code = 77;}
			elseif (($birth_yr - 1976) % 52 == 0){$yr_code = 232;}
			elseif (($birth_yr - 1975) % 52 == 0){$yr_code = 127;}
			elseif (($birth_yr - 1974) % 52 == 0){$yr_code = 22;}
			elseif (($birth_yr - 1973) % 52 == 0){$yr_code = 177;}
			elseif (($birth_yr - 1972) % 52 == 0){$yr_code = 72;}
			elseif (($birth_yr - 1971) % 52 == 0){$yr_code = 227;}
			elseif (($birth_yr - 1970) % 52 == 0){$yr_code = 122;}
			elseif (($birth_yr - 1969) % 52 == 0){$yr_code = 17;}
			elseif (($birth_yr - 1968) % 52 == 0){$yr_code = 172;}
			elseif (($birth_yr - 1967) % 52 == 0){$yr_code = 67;}
			elseif (($birth_yr - 1966) % 52 == 0){$yr_code = 222;}
			elseif (($birth_yr - 1965) % 52 == 0){$yr_code = 117;}
			elseif (($birth_yr - 1964) % 52 == 0){$yr_code = 12;}
			elseif (($birth_yr - 1963) % 52 == 0){$yr_code = 167;}
			elseif (($birth_yr - 1962) % 52 == 0){$yr_code = 62;}
			
			if (($birth_mo === "01")||($birth_mo === "1")){$mo_code = 0;}
			if (($birth_mo === "02")||($birth_mo === "2")){$mo_code = 31;}
			if (($birth_mo === "03")||($birth_mo === "3")){$mo_code = 59;}
			if (($birth_mo === "04")||($birth_mo === "4")){$mo_code = 90;}
			if (($birth_mo === "05")||($birth_mo === "5")){$mo_code = 120;}
			if (($birth_mo === "06")||($birth_mo === "6")){$mo_code = 151;}
			if (($birth_mo === "07")||($birth_mo === "7")){$mo_code = 181;}
			if (($birth_mo === "08")||($birth_mo === "8")){$mo_code = 212;}
			if (($birth_mo === "09")||($birth_mo === "9")){$mo_code = 243;}
			if (($birth_mo === "10")||($birth_mo === "10")){$mo_code = 13;}
			if (($birth_mo === "11")||($birth_mo === "11")){$mo_code = 44;}
			if (($birth_mo === "12")||($birth_mo === "12")){$mo_code = 74;}
			
		// Equation to figure kin is: (yr_code + mo_code + birth_day) (if over 260, subtract 260)
			$yr_mo_day_code = ($yr_code + $mo_code + $birth_day);
			if ($yr_mo_day_code > 260){$yr_mo_day_code = ($yr_mo_day_code - 260); $exc_260 = "- 260";}
			if ($yr_mo_day_code > 260){$yr_mo_day_code = ($yr_mo_day_code - 260);}
	
		} // END if no input error
	} // END if input


// Finally, we check to see if it's leap day -- NOT DAY OUT OF TIME but GAD or 0.0.hunab ku

	if (ms_date_is_leapday($mysql_date)){
		// Adjust back one kin for Leap Day
			$yr_mo_day_code = ($yr_mo_day_code - 1); if ($yr_mo_day_code < 1){$yr_mo_day_code = ($yr_mo_day_code + 260);}
	}

	$kin_ID = $yr_mo_day_code;
	return $kin_ID;
} // END of function tmc_date_mysql_to_kin


// Check to see if this date is a Leap Day
function ms_date_is_leapday($mysql_date){
// Find out if the day is a leap day
	$msdate_pcs = explode("-", $mysql_date);
	$answer = adodb_date('L', strtotime("$msdate_pcs[0]-1-1"));
	if($answer){
		if ((($msdate_pcs[1] === "02")||($msdate_pcs[1] === "2"))&&($msdate_pcs[2] === "29")){
			if (tmc_is_leapyear($msdate_pcs[0])){
				$leap_day = "TRUE";
			}
		}
	}
	return $leap_day;
}


// Here we have the kin number, now to get the mysql dates hmmm...
function guiding_power($tone_num, $tribe_num){

/*
* GET equations for getting relationships to kin: 
	- Guiding Power - 
		* tone: 1, 6 or 11: 	My own power doubled (same kin)
		* tone: 2,7 or 12: 		-2 tribes of same color ()
		* tone: 3, 8 or 13: 	+1 tribe of same color ()
		* tone: 4, 9:       	-1 tribe of same color ()
		* tone: 5, 10:     		+2 tribes of same color ()

	It's about what tribe it is
	- Antipode (challenge) - To find the ANTIPODE, move 10 tribes forward or backward
		- perfect antipode is same tone, but if not same tone, still analog (because of the tribe)
	- Analog (support)  - To find the ANALOG -- your tribe plus analog adds up to 19 -- sum you and analog are 19 -- perfect one is (
		- Same with, subtract or add 19 from tribe
		- if tribe 11, plus adds up to 19
	- Occult Power (hidden gift)
		- 21, use if tribe 11, then 10 is Occult, because it adds up to 21

*/
	
	if (($tone_num === "1")||($tone_num === "6")||($tone_num === "11")){
		$guiding_power_tribe = $tribe_num;
		} elseif (($tone_num === "2")||($tone_num === "7")||($tone_num === "12")){
			$guiding_power_tribe = ($tribe_num - 8);
			if ($guiding_power_tribe > 20){$guiding_power_tribe = ($guiding_power_tribe - 20);}
		} elseif (($tone_num === "3")||($tone_num === "8")||($tone_num === "13")){
			$guiding_power_tribe = ($tribe_num + 4);
			if ($guiding_power_tribe > 20){$guiding_power_tribe = ($guiding_power_tribe - 20);}
		} elseif (($tone_num === "4")||($tone_num === "9")){
			$guiding_power_tribe = ($tribe_num - 4);
			if ($guiding_power_tribe > 20){$guiding_power_tribe = ($guiding_power_tribe - 20);}
		} elseif (($tone_num === "5")||($tone_num === "10")){
			$guiding_power_tribe = ($tribe_num + 8);
			if ($guiding_power_tribe > 20){$guiding_power_tribe = ($guiding_power_tribe - 20);}
		}

		if ($guiding_power_tribe === 0){$guiding_power_tribe = 20;}
		if ($guiding_power_tribe < 0){($guiding_power_tribe = ($guiding_power_tribe + 20));}

	return $guiding_power_tribe;
}

// Tone to Image function
function tone_nm_to_img_num($Tone){
	switch ($Tone) {
		case "MAGNETIC":		$tone_img = "01p.gif";break;
		case "LUNAR":			$tone_img = "02p.gif";break;
		case "ELECTRIC":		$tone_img = "03p.gif";break;
		case "SELF-EXISTING":	$tone_img = "04p.gif";break;
		case "OVERTONE":		$tone_img = "05p.gif";break;
		case "RHYTHMIC":		$tone_img = "06p.gif";break;
		case "RESONANT":		$tone_img = "07p.gif";break;
		case "GALACTIC":		$tone_img = "08p.gif";break;
		case "SOLAR":			$tone_img = "09p.gif";break;
		case "PLANETARY":		$tone_img = "10p.gif";break;
		case "SPECTRAL":		$tone_img = "11p.gif";break;
		case "CRYSTAL":		$tone_img = "12p.gif";break;
		case "COSMIC":			$tone_img = "13p.gif";break;
	}
    return $tone_img;
}

// Tone to Image function
function tone_nm_to_img_num_rev($Tone){
	switch ($Tone) {
		case "MAGNETIC":		$tone_img = "01.png";break;
		case "LUNAR":			$tone_img = "02.png";break;
		case "ELECTRIC":		$tone_img = "03.png";break;
		case "SELF-EXISTING":	$tone_img = "04.png";break;
		case "OVERTONE":		$tone_img = "05.png";break;
		case "RHYTHMIC":		$tone_img = "06.png";break;
		case "RESONANT":		$tone_img = "07.png";break;
		case "GALACTIC":		$tone_img = "08.png";break;
		case "SOLAR":			$tone_img = "09.png";break;
		case "PLANETARY":		$tone_img = "10.png";break;
		case "SPECTRAL":		$tone_img = "11.png";break;
		case "CRYSTAL":		$tone_img = "12.png";break;
		case "COSMIC":			$tone_img = "13.png";break;
	}
    return $tone_img;
}


// Tribe NAME to Tribe Number Image
function tribe_nm_to_img_num($Tribe){
	switch ($Tribe) {
		case "DRAGON":			$tribe_img = "01.png";break;
		case "WIND":			$tribe_img = "02.png";break;
		case "NIGHT":			$tribe_img = "03.png";break;
		case "SEED":			$tribe_img = "04.png";break;
		case "SERPENT":		$tribe_img = "05.png";break;
		case "WORLDBRIDGER":	$tribe_img = "06.png";break;
		case "HAND":			$tribe_img = "07.png";break;
		case "STAR":			$tribe_img = "08.png";break;
		case "MOON":			$tribe_img = "09.png";break;
		case "DOG":			$tribe_img = "10.png";break;
		case "MONKEY":			$tribe_img = "11.png";break;
		case "HUMAN":			$tribe_img = "12.png";break;
		case "SKYWALKER":		$tribe_img = "13.png";break;
		case "WIZARD":			$tribe_img = "14.png";break;
		case "EAGLE":			$tribe_img = "15.png";break;
		case "WARRIOR":		$tribe_img = "16.png";break;
		case "EARTH":			$tribe_img = "17.png";break;
		case "MIRROR":			$tribe_img = "18.png";break;
		case "STORM":			$tribe_img = "19.png";break;
		case "SUN":			$tribe_img = "20.png";break;
	}
    return $tribe_img;
}

// Tribe NAME to Tribe Number Image
function tribe_num_to_img_num($Tribe){
	switch ($Tribe) {
		case "1":			$tribe_img = "01.png";break;
		case "2":			$tribe_img = "02.png";break;
		case "3":			$tribe_img = "03.png";break;
		case "4":			$tribe_img = "04.png";break;
		case "5":			$tribe_img = "05.png";break;
		case "6":			$tribe_img = "06.png";break;
		case "7":			$tribe_img = "07.png";break;
		case "8":			$tribe_img = "08.png";break;
		case "9":			$tribe_img = "09.png";break;
		case "10":		$tribe_img = "10.png";break;
		case "11":		$tribe_img = "11.png";break;
		case "12":		$tribe_img = "12.png";break;
		case "13":		$tribe_img = "13.png";break;
		case "14":		$tribe_img = "14.png";break;
		case "15":		$tribe_img = "15.png";break;
		case "16":		$tribe_img = "16.png";break;
		case "17":		$tribe_img = "17.png";break;
		case "18":		$tribe_img = "18.png";break;
		case "19":		$tribe_img = "19.png";break;
		case "20":		$tribe_img = "20.png";break;
	}
    return $tribe_img;
}

// Date MySQL to SHORT DATE
function tmc_date_mysql_to_short($mysql_date){
	$mysql_date_pcs = explode('-',$mysql_date);
	$year = $mysql_date_pcs[0];
	$month = $mysql_date_pcs[1];
	$day = $mysql_date_pcs[2];

	switch ($month){
		case "01":  $month = "1"; break;
		case "02":  $month = "2"; break;
		case "03":  $month = "3"; break;
		case "04":  $month = "4"; break;
		case "05":  $month = "5"; break;
		case "06":  $month = "6"; break;
		case "07":  $month = "7"; break;
		case "08":  $month = "8"; break;
		case "09":  $month = "9"; break;
		case "10":  $month = "10"; break;
		case "11":  $month = "11"; break;
		case "12":  $month = "12"; break;
    }

	switch ($day){
		case "01":  $day = "1"; break;
		case "02":  $day = "2"; break;
		case "03":  $day = "3"; break;
		case "04":  $day = "4"; break;
		case "05":  $day = "5"; break;
		case "06":  $day = "6"; break;
		case "07":  $day = "7"; break;
		case "08":  $day = "8"; break;
		case "09":  $day = "9"; break;
    }

	$date_full = "$month/$day/$year";
	return $date_full;
}


// Date MySQL to SHORT DATE
function date_mysql_to_very_short($mysql_date){
	$mysql_date_pcs = explode('-',$mysql_date);
	$year = $mysql_date_pcs[0];
	$month = $mysql_date_pcs[1];
	$day = $mysql_date_pcs[2];

	switch ($month){
		case "01":  $month = "1"; break;
		case "02":  $month = "2"; break;
		case "03":  $month = "3"; break;
		case "04":  $month = "4"; break;
		case "05":  $month = "5"; break;
		case "06":  $month = "6"; break;
		case "07":  $month = "7"; break;
		case "08":  $month = "8"; break;
		case "09":  $month = "9"; break;
		case "10":  $month = "10"; break;
		case "11":  $month = "11"; break;
		case "12":  $month = "12"; break;
    }

	switch ($day){
		case "01":  $day = "1"; break;
		case "02":  $day = "2"; break;
		case "03":  $day = "3"; break;
		case "04":  $day = "4"; break;
		case "05":  $day = "5"; break;
		case "06":  $day = "6"; break;
		case "07":  $day = "7"; break;
		case "08":  $day = "8"; break;
		case "09":  $day = "9"; break;
    }

	$year = substr("$year", -2);    // turns 2010 to 10

	$date_full = "$month/$day/$year";
	return $date_full;
}

// tmc_truncate long names
function tmc_truncate($string, $max, $replacement){
    if (strlen($string) <= $max)
    {
        return $string;
    }
    $leave = $max - strlen ($replacement);
    return substr_replace($string, $replacement, $leave);
}

// Tone NAME to Tone Number
function tone_name_to_num($tone_name){
	switch ($tone_name){
		case "MAGNETIC":  		$tone_num = "1"; break;
		case "LUNAR":  		$tone_num = "2"; break;
		case "ELECTRIC":  		$tone_num = "3"; break;
		case "SELF-EXISTING":  	$tone_num = "4"; break;
		case "OVERTONE":  		$tone_num = "5"; break;
		case "RHYTHMIC":		$tone_num = "6"; break;
		case "RESONANT":		$tone_num = "7"; break;
		case "GALACTIC":		$tone_num = "8"; break;
		case "SOLAR":			$tone_num = "9"; break;
		case "PLANETARY":		$tone_num = "10"; break;
		case "SPECTRAL":		$tone_num = "11"; break;
		case "CRYSTAL":		$tone_num = "12"; break;
		case "COSMIC":			$tone_num = "13"; break;
    }
	return $tone_num;
}

// Tone NAME to Tone Number
function tmc_tone_num_to_name($tone_num){
	switch ($tone_num){
		case 1:  $tone_name = "Magnetic";		break;
		case 2:  $tone_name = "Lunar";  		break;
		case 3:  $tone_name = "Electric";  	break;
		case 4:  $tone_name = "Self-Existing";	break;
		case 5:  $tone_name = "Overtone";  	break;
		case 6:  $tone_name = "Rhythmic";		break;
		case 7:  $tone_name = "Resonant";		break;
		case 8:  $tone_name = "Galactic";		break;
		case 9:  $tone_name = "Solar";		break;
		case 10: $tone_name = "Planetary";		break;
		case 11: $tone_name = "Spectral";		break;
		case 12: $tone_name = "Crystal";		break;
		case 13: $tone_name = "Cosmic";		break;
    }
	return $tone_name;
}

// Tribe NAME to Tribe Number
function tribe_name_to_num($tribe_name){
	switch ($tribe_name){
		case "DRAGON":			$tribe_num = "1"; break;
		case "WIND":			$tribe_num = "2"; break;
		case "NIGHT":			$tribe_num = "3"; break;
		case "SEED":			$tribe_num = "4"; break;
		case "SERPENT":		$tribe_num = "5"; break;
		case "WORLDBRIDGER":	$tribe_num = "6"; break;
		case "HAND":			$tribe_num = "7"; break;
		case "STAR":			$tribe_num = "8"; break;
		case "MOON":			$tribe_num = "9"; break;
		case "DOG":			$tribe_num = "10"; break;
		case "MONKEY":			$tribe_num = "11"; break;
		case "HUMAN":			$tribe_num = "12"; break;
		case "SKYWALKER":		$tribe_num = "13"; break;
		case "WIZARD":			$tribe_num = "14"; break;
		case "EAGLE":			$tribe_num = "15"; break;
		case "WARRIOR":		$tribe_num = "16"; break;
		case "EARTH":			$tribe_num = "17"; break;
		case "MIRROR":			$tribe_num = "18"; break;
		case "STORM":			$tribe_num = "19"; break;
		case "SUN":			$tribe_num = "20"; break;
    }
	return $tribe_num;
}


// Tribe NUMBER to Tribe NAME
function tribe_num_to_name($tribe_num){
	switch ($tribe_num){
		case 1:		$tribe_name = "DRAGON"; break;
		case 2:		$tribe_name = "WIND"; break;
		case 3:		$tribe_name = "NIGHT"; break;
		case 4:		$tribe_name = "SEED"; break;
		case 5:		$tribe_name = "SERPENT"; break;
		case 6:		$tribe_name = "WORLDBRIDGER"; break;
		case 7:		$tribe_name = "HAND"; break;
		case 8:		$tribe_name = "STAR"; break;
		case 9:		$tribe_name = "MOON"; break;
		case 10:		$tribe_name = "DOG"; break;
		case 11:		$tribe_name = "MONKEY"; break;
		case 12:		$tribe_name = "HUMAN"; break;
		case 13:		$tribe_name = "SKYWALKER"; break;
		case 14:		$tribe_name = "WIZARD"; break;
		case 15:		$tribe_name = "EAGLE"; break;
		case 16:		$tribe_name = "WARRIOR"; break;
		case 17:		$tribe_name = "EARTH"; break;
		case 18:		$tribe_name = "MIRROR"; break;
		case 19:		$tribe_name = "STORM"; break;
		case 20:		$tribe_name = "SUN"; break;
    }
	return $tribe_name;
}

// Tribe NUMBER to Tribe COLOR
function tribe_num_to_color($tribe_num){
	switch ($tribe_num){
		case 1:		$tribe_color = "RED"; break;
		case 2:		$tribe_color = "WHITE"; break;
		case 3:		$tribe_color = "BLUE"; break;
		case 4:		$tribe_color = "YELLOW"; break;
		case 5:		$tribe_color = "RED"; break;
		case 6:		$tribe_color = "WHITE"; break;
		case 7:		$tribe_color = "BLUE"; break;
		case 8:		$tribe_color = "YELLOW"; break;
		case 9:		$tribe_color = "RED"; break;
		case 10:		$tribe_color = "WHITE"; break;
		case 11:		$tribe_color = "BLUE"; break;
		case 12:		$tribe_color = "YELLOW"; break;
		case 13:		$tribe_color = "RED"; break;
		case 14:		$tribe_color = "WHITE"; break;
		case 15:		$tribe_color = "BLUE"; break;
		case 16:		$tribe_color = "YELLOW"; break;
		case 17:		$tribe_color = "RED"; break;
		case 18:		$tribe_color = "WHITE"; break;
		case 19:		$tribe_color = "BLUE"; break;
		case 20:		$tribe_color = "YELLOW"; break;
    }
	return $tribe_color;
}

// The REVERSE DECODER:
function kin_to_next_gb($start_kin_id){

	// Get kin for today
	$today_mysql_date = adodb_date("Y-m-d"); // For decoding
	$today_kin = tmc_date_mysql_to_kin($today_mysql_date, AD);

	// Now that we have today's kin, we can do some math
	$days_to_gb = ($start_kin_id - $today_kin);
	if ($days_to_gb > 260){$days_to_gb = $days_to_gb - 260;}
	if ($days_to_gb < 1){$days_to_gb = $days_to_gb + 260;}

	// Convert this date to array
	$today_date_array = explode("-", $today_mysql_date);
	$dcode_yr  = 	$today_date_array[0];
	$dcode_mo  = 	$today_date_array[1];
	$dcode_day = 	$today_date_array[2];
	
	// Determine the date of the next GB
	$next_gb_date_mysql = adodb_date('Y-m-d',adodb_mktime(0, 0, 0, $dcode_mo, $dcode_day+$days_to_gb, $dcode_yr));

	// Return array
	return array($next_gb_date_mysql, $days_to_gb);
}


// GET WAVESPELL kin_to_wavespell
function kin_to_wavespell($kin_ID, $tone_num){
	// This gets the last kin with tone #1
	$wavespell_kin = ($kin_ID - ($tone_num - 1));
	// Adjust in case we have a negative kin number
	if ($wavespell_kin < 1)($wavespell_kin = $wavespell_kin + 260);
// Return kin number for wavespell beginning
	return $wavespell_kin;
}


// Count days between two dates
      /**
       * Calculating the difference between two dates
       * @author: Elliott White
       * @author: Jonathan D Eisenhamer.
       * @link: http://www.quepublishing.com/articles/article.asp?p=664657&rl=1
       * @since: Dec 1, 2006.
       */
// Used in calendar.php

// Will return the number of days between the two dates passed in
function tmc_count_days($a, $b){

// First we need to break these dates into their constituent parts:
	$gd_a = adodb_getdate( $a );
	$gd_b = adodb_getdate( $b );
       
// Now recreate these timestamps, based upon noon on each day
// The specific time doesn't matter but it must be the same each day
	$a_new = adodb_mktime( 12, 0, 0, $gd_a['mon'], $gd_a['mday'], $gd_a['year'] );
	$b_new = adodb_mktime( 12, 0, 0, $gd_b['mon'], $gd_b['mday'], $gd_b['year'] );
       
// Subtract these two numbers and divide by the number of seconds in a
// day. Round the result since crossing over a daylight savings time
// barrier will cause this time to be off by an hour or two.
	return round(abs($a_new - $b_new) / 86400);
}


function sql_date_shift($date, $shift){
	return adodb_date("Y-m-d" , strtotime($shift, strtotime($date)));
}

function day_of_week($date, $shift){
	return adodb_date("l" , strtotime($shift, strtotime($date)));
}

// Day Number of Plasma
function gday_nam_to_may_name($day_count){
	switch ($day_count) {
		case "1":			$may_nm_day = "Dali";break;
		case "2":			$may_nm_day = "Seli";break;
		case "3":			$may_nm_day = "Gamma";break;
		case "4":			$may_nm_day = "Kali";break;
		case "5":			$may_nm_day = "Alpha";break;
		case "6":			$may_nm_day = "Limi";break;
		case "7":			$may_nm_day = "Silio";break;
	}
    return $may_nm_day;
}

// Get the starting Gregorian year for the 13-moon calendar
function ms_moon_start_yr($dcode_mo, $dcode_day, $dcode_yr) {
	if ($dcode_mo < 7){
		$start_year = ($dcode_yr - 1);
	}

	if ($dcode_mo > 7){
		$start_year = $dcode_yr;
	}
	
	if ($dcode_mo == 7){
		if ($dcode_day > 25){
			$start_year = $dcode_yr;
		} elseif ($dcode_day < 26){
			$start_year = ($dcode_yr - 1);
		}
	}
	return $start_year;
}


/*  Not every year that is divisible by 4 is a leap year. There are other conditions. Here's the complete list:

   1. Every year that is evenly divisible by four is a leap year;
   2. of those years, if it can be evenly divided by 100, it is NOT a leap year, unless
   3. the year is evenly divisible by 400. Then it is a leap year.
*/

function tmc_is_leapyear($year) {
	if ( ($year%4) != 0 )
	{     return false;     }
	
	if ( ($year%100)==0 )
	{
	     if ( ($year%400) == 0 )
	     {     return true;     }
	     else
	     {     return false;    }
	}
	else
	{     return true;     }
}


// ms_date_moon_array - creates an array of dates & moons for every day of the 13-moon solar cycle - from a MySQL date
function ms_date_moon_array($dcode_mo, $dcode_day, $dcode_yr){
// Get starting YEAR
	$starting_year = ms_moon_start_yr($dcode_mo, $dcode_day, $dcode_yr);
	// Set starting g date of M cal
	$gyear= $starting_year;
	$gmonth= 7;
	$gday= 25;
	// Set increment vars
	$inc_days = 1;
	$inc_mdays = 1;
	$inc_m_moon = 1;
	$inc_m_day = 1;
	// Loop through all 364 days 
	while ($inc_days <= 364){
// Get number of days in that month (skipping over LEAP DAY just like it doesn't exist!!!)
		switch ($gmonth) {
			case "1":			$num_days_ms_mo = "31";break;
			case "2":			$num_days_ms_mo = "28";break;
			case "3":			$num_days_ms_mo = "31";break;
			case "4":			$num_days_ms_mo = "30";break;
			case "5":			$num_days_ms_mo = "31";break;
			case "6":			$num_days_ms_mo = "30";break;
			case "7":			$num_days_ms_mo = "31";break;
			case "8":			$num_days_ms_mo = "31";break;
			case "9":			$num_days_ms_mo = "30";break;
			case "10":		$num_days_ms_mo = "31";break;
			case "11":		$num_days_ms_mo = "30";break;
			case "12":		$num_days_ms_mo = "31";break;
		}
// Increment greg day
		if($gday <= $num_days_ms_mo){
			$gday++;
		}
		if ($gday > $num_days_ms_mo){
// reset greg day
			$gday = 1;
// Increment greg month
			$gmonth++;
		}
// Go to January of next year
		if ($gmonth === 13){
			$gmonth = 1;
			$gyear = ($gyear + 1);
		}
		$this_ms_date = "$gyear-$gmonth-$gday";
	// Increment the M Moon
	// reset inc_m_day
		if ($inc_m_day === 29){
			$inc_m_day = 1;
			$inc_m_moon++;
		}
// Put m day in array
		$this_m_day[$inc_m_moon][] = "$inc_m_moon"."--"."$this_ms_date";

		$inc_m_day++;
		$inc_days++;
	}
	// Return array
	return $this_m_day;
}


// Calculate Moon Phase
/*
Adaptation en php du fameux et excellent scripte Astro-MoonPhase de Brett Hamilton écrit en Perl.
http://search.cpan.org/~brett/Astro-MoonPhase-0.60/

*/
class Moon {
	function phase($Year, $Month, $Day, $Hour, $Minutes, $Seconds){
		$DateSec = mktime($Hour, $Minutes, $Seconds, $Month, $Day, $Year, 0);
		ini_set(precision, "20");	//Defini la precision des calcules
		# Astronomical constants.
		$Epoch				= 2444238.5;		# 1980 January 0.0
		# Constants defining the Sun's apparent orbit.
		$Elonge				= 278.833540;		# ecliptic longitude of the Sun at epoch 1980.0
		$Elongp				= 282.596403;		# ecliptic longitude of the Sun at perigee
		$Eccent				= 0.016718;			# eccentricity of Earth's orbit
		$Sunsmax			= 1.495985e8;		# semi-major axis of Earth's orbit, km
		$Sunangsiz			= 0.533128;			# sun's angular size, degrees, at semi-major axis distance
		# Elements of the Moon's orbit, epoch 1980.0.
		$Mmlong				= 64.975464;		# moon's mean longitude at the epoch
		$Mmlongp			= 349.383063;		# mean longitude of the perigee at the epoch
		$Mlnode				= 151.950429;		# mean longitude of the node at the epoch
		$Minc				= 5.145396;			# inclination of the Moon's orbit
		$Mecc				= 0.054900;			# eccentricity of the Moon's orbit
		$Mangsiz			= 0.5181;			# moon's angular size at distance a from Earth
		$Msmax				= 384401.0;			# semi-major axis of Moon's orbit in km
		$Mparallax			= 0.9507;			# parallax at distance a from Earth
		$Synmonth			= 29.53058868;		# synodic month (new Moon to new Moon)
		$pdate = Moon::jtime($DateSec);
		$pphase;				# illuminated fraction
		$mage;					# age of moon in days
		$dist;					# distance in kilometres
		$angdia;				# angular diameter in degrees
		$sudist;				# distance to Sun
		$suangdia;				# sun's angular diameter

		# Calculation of the Sun's position.
		$Day = $pdate - $Epoch;										# date within epoch
		$N = Moon::fixangle((360 / 365.2422) * $Day);				# mean anomaly of the Sun
		$M = Moon::fixangle($N + $Elonge - $Elongp);				# convert from perigee
										# co-ordinates to epoch 1980.0
		$Ec = Moon::kepler($M, $Eccent);							# solve equation of Kepler
		$Ec = sqrt((1 + $Eccent) / (1 - $Eccent)) * tan($Ec / 2);
		$Ec = 2 * Moon::todeg(atan($Ec));							# true anomaly
		$Lambdasun = Moon::fixangle($Ec + $Elongp);					# Sun's geocentric ecliptic
										# longitude
		# Orbital distance factor.
		$F = ((1 + $Eccent * cos(Moon::torad($Ec))) / (1 - $Eccent * $Eccent));
		$SunDist = $Sunsmax / $F;									# distance to Sun in km
		$SunAng = $F * $Sunangsiz;									# Sun's angular size in degrees

		# Calculation of the Moon's position.

		# Moon's mean longitude.
		$ml = Moon::fixangle(13.1763966 * $Day + $Mmlong);
		# Moon's mean anomaly.
		$MM = Moon::fixangle($ml - 0.1114041 * $Day - $Mmlongp);
		# Moon's ascending node mean longitude.
		$MN = Moon::fixangle($Mlnode - 0.0529539 * $Day);
		# Evection.
		$Ev = 1.2739 * sin(Moon::torad(2 * ($ml - $Lambdasun) - $MM));
		# Annual equation.
		$Ae = 0.1858 * sin(Moon::torad($M));
		# Correction term.
		$A3 = 0.37 * sin(Moon::torad($M));
		# Corrected anomaly.
		$MmP = $MM + $Ev - $Ae - $A3;
		# Correction for the equation of the centre.
		$mEc = 6.2886 * sin(Moon::torad($MmP));
		# Another correction term.
		$A4 = 0.214 * sin(Moon::torad(2 * $MmP));
		# Corrected longitude.
		$lP = $ml + $Ev + $mEc - $Ae + $A4;
		# Variation.
		$V = 0.6583 * sin(Moon::torad(2 * ($lP - $Lambdasun)));
		# True longitude.
		$lPP = $lP + $V;
		# Corrected longitude of the node.
		$NP = $MN - 0.16 * sin(Moon::torad($M));
		# Y inclination coordinate.
		$y = sin(Moon::torad($lPP - $NP)) * cos(Moon::torad($Minc));
		# X inclination coordinate.
		$x = cos(Moon::torad($lPP - $NP));
		# Ecliptic longitude.
		$Lambdamoon = Moon::todeg(atan2($y, $x));
		$Lambdamoon += $NP;
		# Ecliptic latitude.
		$BetaM = Moon::todeg(asin(sin(Moon::torad($lPP - $NP)) * sin(Moon::torad($Minc))));
		# Calculation of the phase of the Moon.
		# Age of the Moon in degrees.
		$MoonAge = $lPP - $Lambdasun;
		# Phase of the Moon.
		$MoonPhase = (1 - cos(Moon::torad($MoonAge))) / 2;
		# Calculate distance of moon from the centre of the Earth.
		$MoonDist = ($Msmax * (1 - $Mecc * $Mecc)) / (1 + $Mecc * cos(Moon::torad($MmP + $mEc)));
		# Calculate Moon's angular diameter.
		$MoonDFrac = $MoonDist / $Msmax;
		$MoonAng = $Mangsiz / $MoonDFrac;
		# Calculate Moon's parallax.
		$MoonPar = $Mparallax / $MoonDFrac;
		$pphase = $MoonPhase;									# illuminated fraction
		$mage = $Synmonth * (Moon::fixangle($MoonAge) / 360.0);		# age of moon in days
		$dist = $MoonDist;										# distance in kilometres
		$angdia = $MoonAng;										# angular diameter in degrees
		$sudist = $SunDist;										# distance to Sun
		$suangdia = $SunAng;									# sun's angular diameter
		$mpfrac = Moon::fixangle($MoonAge) / 360.0;
		return array($pphase, $mage, $dist, $angdia, $sudist, $suangdia, $mpfrac, $mpfrac);
	}

	function fixangle($x)	{ return ($x - 360.0 * (floor($x / 360.0))); }	# fix angle
	function torad($x)	{ return ($x * (M_PI / 180.0)); }				# deg->rad
	function todeg($x)	{ return ($x * (180.0 / M_PI)); }				# rad->deg
	function jtime($t)	{
		$julian = ($t / 86400) + 2440587.5;	# (seconds /(seconds per day)) + julian date of epoch		2440587.5 / 86400 = 28,24753472222 Days
		return ($julian);
	}
	function kepler($m, $ecc) {
		$EPSILON = 1e-6;
		$m = Moon::torad($m);
		$e = $m;
		while (abs($delta) > $EPSILON) {
			$delta = $e - $ecc * sin($e) - $m;
			$e -= $delta / (1 - $ecc * cos($e));
			}
		return ($e);
	}
}

// Translate URL for SEO
function translate_kin_to_seo($tran_kin) {
	switch ($tran_kin) {
     	case "1":		$translation = "RED-MAGNETIC-DRAGON"; break;
     	case "2":		$translation = "WHITE-LUNAR-WIND"; break;
     	case "3":		$translation = "BLUE-ELECTRIC-NIGHT"; break;
     	case "4":		$translation = "YELLOW-SELF-EXISTING-SEED"; break;
     	case "5":		$translation = "RED-OVERTONE-SERPENT"; break;
     	case "6":		$translation = "WHITE-RHYTHMIC-WORLDBRIDGER"; break;
     	case "7":		$translation = "BLUE-RESONANT-HAND"; break;
     	case "8":		$translation = "YELLOW-GALACTIC-STAR"; break;
     	case "9":		$translation = "RED-SOLAR-MOON"; break;
     	case "10":	$translation = "WHITE-PLANETARY-DOG"; break;
     	case "11":	$translation = "BLUE-SPECTRAL-MONKEY"; break;
     	case "12":	$translation = "YELLOW-CRYSTAL-HUMAN"; break;
     	case "13":	$translation = "RED-COSMIC-SKYWALKER"; break;
     	case "14":	$translation = "WHITE-MAGNETIC-WIZARD"; break;
     	case "15":	$translation = "BLUE-LUNAR-EAGLE"; break;
     	case "16":	$translation = "YELLOW-ELECTRIC-WARRIOR"; break;
     	case "17":	$translation = "RED-SELF-EXISTING-EARTH"; break;
     	case "18":	$translation = "WHITE-OVERTONE-MIRROR"; break;
     	case "19":	$translation = "BLUE-RHYTHMIC-STORM"; break;
     	case "20":	$translation = "YELLOW-RESONANT-SUN"; break;
     	case "21":	$translation = "RED-GALACTIC-DRAGON"; break;
     	case "22":	$translation = "WHITE-SOLAR-WIND"; break;
     	case "23":	$translation = "BLUE-PLANETARY-NIGHT"; break;
     	case "24":	$translation = "YELLOW-SPECTRAL-SEED"; break;
     	case "25":	$translation = "RED-CRYSTAL-SERPENT"; break;
     	case "26":	$translation = "WHITE-COSMIC-WORLDBRIDGER"; break;
     	case "27":	$translation = "BLUE-MAGNETIC-HAND"; break;
     	case "28":	$translation = "YELLOW-LUNAR-STAR"; break;
     	case "29":	$translation = "RED-ELECTRIC-MOON"; break;
     	case "30":	$translation = "WHITE-SELF-EXISTING-DOG"; break;
     	case "31":	$translation = "BLUE-OVERTONE-MONKEY"; break;
     	case "32":	$translation = "YELLOW-RHYTHMIC-HUMAN"; break;
     	case "33":	$translation = "RED-RESONANT-SKYWALKER"; break;
     	case "34":	$translation = "WHITE-GALACTIC-WIZARD"; break;
     	case "35":	$translation = "BLUE-SOLAR-EAGLE"; break;
     	case "36":	$translation = "YELLOW-PLANETARY-WARRIOR"; break;
     	case "37":	$translation = "RED-SPECTRAL-EARTH"; break;
     	case "38":	$translation = "WHITE-CRYSTAL-MIRROR"; break;
     	case "39":	$translation = "BLUE-COSMIC-STORM"; break;
     	case "40":	$translation = "YELLOW-MAGNETIC-SUN"; break;
     	case "41":	$translation = "RED-LUNAR-DRAGON"; break;
     	case "42":	$translation = "WHITE-ELECTRIC-WIND"; break;
     	case "43":	$translation = "BLUE-SELF-EXISTING-NIGHT"; break;
     	case "44":	$translation = "YELLOW-OVERTONE-SEED"; break;
     	case "45":	$translation = "RED-RHYTHMIC-SERPENT"; break;
     	case "46":	$translation = "WHITE-RESONANT-WORLDBRIDGER"; break;
     	case "47":	$translation = "BLUE-GALACTIC-HAND"; break;
     	case "48":	$translation = "YELLOW-SOLAR-STAR"; break;
     	case "49":	$translation = "RED-PLANETARY-MOON"; break;
     	case "50":	$translation = "WHITE-SPECTRAL-DOG"; break;
     	case "51":	$translation = "BLUE-CRYSTAL-MONKEY"; break;
     	case "52":	$translation = "YELLOW-COSMIC-HUMAN"; break;
     	case "53":	$translation = "RED-MAGNETIC-SKYWALKER"; break;
     	case "54":	$translation = "WHITE-LUNAR-WIZARD"; break;
     	case "55":	$translation = "BLUE-ELECTRIC-EAGLE"; break;
     	case "56":	$translation = "YELLOW-SELF-EXISTING-WARRIOR"; break;
     	case "57":	$translation = "RED-OVERTONE-EARTH"; break;
     	case "58":	$translation = "WHITE-RHYTHMIC-MIRROR"; break;
     	case "59":	$translation = "BLUE-RESONANT-STORM"; break;
     	case "60":	$translation = "YELLOW-GALACTIC-SUN"; break;
     	case "61":	$translation = "RED-SOLAR-DRAGON"; break;
     	case "62":	$translation = "WHITE-PLANETARY-WIND"; break;
     	case "63":	$translation = "BLUE-SPECTRAL-NIGHT"; break;
     	case "64":	$translation = "YELLOW-CRYSTAL-SEED"; break;
     	case "65":	$translation = "RED-COSMIC-SERPENT"; break;
     	case "66":	$translation = "WHITE-MAGNETIC-WORLDBRIDGER"; break;
     	case "67":	$translation = "BLUE-LUNAR-HAND"; break;
     	case "68":	$translation = "YELLOW-ELECTRIC-STAR"; break;
     	case "69":	$translation = "RED-SELF-EXISTING-MOON"; break;
     	case "70":	$translation = "WHITE-OVERTONE-DOG"; break;
     	case "71":	$translation = "BLUE-RHYTHMIC-MONKEY"; break;
     	case "72":	$translation = "YELLOW-RESONANT-HUMAN"; break;
     	case "73":	$translation = "RED-GALACTIC-SKYWALKER"; break;
     	case "74":	$translation = "WHITE-SOLAR-WIZARD"; break;
     	case "75":	$translation = "BLUE-PLANETARY-EAGLE"; break;
     	case "76":	$translation = "YELLOW-SPECTRAL-WARRIOR"; break;
     	case "77":	$translation = "RED-CRYSTAL-EARTH"; break;
     	case "78":	$translation = "WHITE-COSMIC-MIRROR"; break;
     	case "79":	$translation = "BLUE-MAGNETIC-STORM"; break;
     	case "80":	$translation = "YELLOW-LUNAR-SUN"; break;
     	case "81":	$translation = "RED-ELECTRIC-DRAGON"; break;
     	case "82":	$translation = "WHITE-SELF-EXISTING-WIND"; break;
     	case "83":	$translation = "BLUE-OVERTONE-NIGHT"; break;
     	case "84":	$translation = "YELLOW-RHYTHMIC-SEED"; break;
     	case "85":	$translation = "RED-RESONANT-SERPENT"; break;
     	case "86":	$translation = "WHITE-GALACTIC-WORLDBRIDGER"; break;
     	case "87":	$translation = "BLUE-SOLAR-HAND"; break;
     	case "88":	$translation = "YELLOW-PLANETARY-STAR"; break;
     	case "89":	$translation = "RED-SPECTRAL-MOON"; break;
     	case "90":	$translation = "WHITE-CRYSTAL-DOG"; break;
     	case "91":	$translation = "BLUE-COSMIC-MONKEY"; break;
     	case "92":	$translation = "YELLOW-MAGNETIC-HUMAN"; break;
     	case "93":	$translation = "RED-LUNAR-SKYWALKER"; break;
     	case "94":	$translation = "WHITE-ELECTRIC-WIZARD"; break;
     	case "95":	$translation = "BLUE-SELF-EXISTING-EAGLE"; break;
     	case "96":	$translation = "YELLOW-OVERTONE-WARRIOR"; break;
     	case "97":	$translation = "RED-RHYTHMIC-EARTH"; break;
     	case "98":	$translation = "WHITE-RESONANT-MIRROR"; break;
     	case "99":	$translation = "BLUE-GALACTIC-STORM"; break;
     	case "100":	$translation = "YELLOW-SOLAR-SUN"; break;
     	case "101":	$translation = "RED-PLANETARY-DRAGON"; break;
     	case "102":	$translation = "WHITE-SPECTRAL-WIND"; break;
     	case "103":	$translation = "BLUE-CRYSTAL-NIGHT"; break;
     	case "104":	$translation = "YELLOW-COSMIC-SEED"; break;
     	case "105":	$translation = "RED-MAGNETIC-SERPENT"; break;
     	case "106":	$translation = "WHITE-LUNAR-WORLDBRIDGER"; break;
     	case "107":	$translation = "BLUE-ELECTRIC-HAND"; break;
     	case "108":	$translation = "YELLOW-SELF-EXISTING-STAR"; break;
     	case "109":	$translation = "RED-OVERTONE-MOON"; break;
     	case "110":	$translation = "WHITE-RHYTHMIC-DOG"; break;
     	case "111":	$translation = "BLUE-RESONANT-MONKEY"; break;
     	case "112":	$translation = "YELLOW-GALACTIC-HUMAN"; break;
     	case "113":	$translation = "RED-SOLAR-SKYWALKER"; break;
     	case "114":	$translation = "WHITE-PLANETARY-WIZARD"; break;
     	case "115":	$translation = "BLUE-SPECTRAL-EAGLE"; break;
     	case "116":	$translation = "YELLOW-CRYSTAL-WARRIOR"; break;
     	case "117":	$translation = "RED-COSMIC-EARTH"; break;
     	case "118":	$translation = "WHITE-MAGNETIC-MIRROR"; break;
     	case "119":	$translation = "BLUE-LUNAR-STORM"; break;
     	case "120":	$translation = "YELLOW-ELECTRIC-SUN"; break;
     	case "121":	$translation = "RED-SELF-EXISTING-DRAGON"; break;
     	case "122":	$translation = "WHITE-OVERTONE-WIND"; break;
     	case "123":	$translation = "BLUE-RHYTHMIC-NIGHT"; break;
     	case "124":	$translation = "YELLOW-RESONANT-SEED"; break;
     	case "125":	$translation = "RED-GALACTIC-SERPENT"; break;
     	case "126":	$translation = "WHITE-SOLAR-WORLDBRIDGER"; break;
     	case "127":	$translation = "BLUE-PLANETARY-HAND"; break;
     	case "128":	$translation = "YELLOW-SPECTRAL-STAR"; break;
     	case "129":	$translation = "RED-CRYSTAL-MOON"; break;
     	case "130":	$translation = "WHITE-COSMIC-DOG"; break;
     	case "131":	$translation = "BLUE-MAGNETIC-MONKEY"; break;
     	case "132":	$translation = "YELLOW-LUNAR-HUMAN"; break;
     	case "133":	$translation = "RED-ELECTRIC-SKYWALKER"; break;
     	case "134":	$translation = "WHITE-SELF-EXISTING-WIZARD"; break;
     	case "135":	$translation = "BLUE-OVERTONE-EAGLE"; break;
     	case "136":	$translation = "YELLOW-RHYTHMIC-WARRIOR"; break;
     	case "137":	$translation = "RED-RESONANT-EARTH"; break;
     	case "138":	$translation = "WHITE-GALACTIC-MIRROR"; break;
     	case "139":	$translation = "BLUE-SOLAR-STORM"; break;
     	case "140":	$translation = "YELLOW-PLANETARY-SUN"; break;
     	case "141":	$translation = "RED-SPECTRAL-DRAGON"; break;
     	case "142":	$translation = "WHITE-CRYSTAL-WIND"; break;
     	case "143":	$translation = "BLUE-COSMIC-NIGHT"; break;
     	case "144":	$translation = "YELLOW-MAGNETIC-SEED"; break;
     	case "145":	$translation = "RED-LUNAR-SERPENT"; break;
     	case "146":	$translation = "WHITE-ELECTRIC-WORLDBRIDGER"; break;
     	case "147":	$translation = "BLUE-SELF-EXISTING-HAND"; break;
     	case "148":	$translation = "YELLOW-OVERTONE-STAR"; break;
     	case "149":	$translation = "RED-RHYTHMIC-MOON"; break;
     	case "150":	$translation = "WHITE-RESONANT-DOG"; break;
     	case "151":	$translation = "BLUE-GALACTIC-MONKEY"; break;
     	case "152":	$translation = "YELLOW-SOLAR-HUMAN"; break;
     	case "153":	$translation = "RED-PLANETARY-SKYWALKER"; break;
     	case "154":	$translation = "WHITE-SPECTRAL-WIZARD"; break;
     	case "155":	$translation = "BLUE-CRYSTAL-EAGLE"; break;
     	case "156":	$translation = "YELLOW-COSMIC-WARRIOR"; break;
     	case "157":	$translation = "RED-MAGNETIC-EARTH"; break;
     	case "158":	$translation = "WHITE-LUNAR-MIRROR"; break;
     	case "159":	$translation = "BLUE-ELECTRIC-STORM"; break;
     	case "160":	$translation = "YELLOW-SELF-EXISTING-SUN"; break;
     	case "161":	$translation = "RED-OVERTONE-DRAGON"; break;
     	case "162":	$translation = "WHITE-RHYTHMIC-WIND"; break;
     	case "163":	$translation = "BLUE-RESONANT-NIGHT"; break;
     	case "164":	$translation = "YELLOW-GALACTIC-SEED"; break;
     	case "165":	$translation = "RED-SOLAR-SERPENT"; break;
     	case "166":	$translation = "WHITE-PLANETARY-WORLDBRIDGER"; break;
     	case "167":	$translation = "BLUE-SPECTRAL-HAND"; break;
     	case "168":	$translation = "YELLOW-CRYSTAL-STAR"; break;
     	case "169":	$translation = "RED-COSMIC-MOON"; break;
     	case "170":	$translation = "WHITE-MAGNETIC-DOG"; break;
     	case "171":	$translation = "BLUE-LUNAR-MONKEY"; break;
     	case "172":	$translation = "YELLOW-ELECTRIC-HUMAN"; break;
     	case "173":	$translation = "RED-SELF-EXISTING-SKYWALKER"; break;
     	case "174":	$translation = "WHITE-OVERTONE-WIZARD"; break;
     	case "175":	$translation = "BLUE-RHYTHMIC-EAGLE"; break;
     	case "176":	$translation = "YELLOW-RESONANT-WARRIOR"; break;
     	case "177":	$translation = "RED-GALACTIC-EARTH"; break;
     	case "178":	$translation = "WHITE-SOLAR-MIRROR"; break;
     	case "179":	$translation = "BLUE-PLANETARY-STORM"; break;
     	case "180":	$translation = "YELLOW-SPECTRAL-SUN"; break;
     	case "181":	$translation = "RED-CRYSTAL-DRAGON"; break;
     	case "182":	$translation = "WHITE-COSMIC-WIND"; break;
     	case "183":	$translation = "BLUE-MAGNETIC-NIGHT"; break;
     	case "184":	$translation = "YELLOW-LUNAR-SEED"; break;
     	case "185":	$translation = "RED-ELECTRIC-SERPENT"; break;
     	case "186":	$translation = "WHITE-SELF-EXISTING-WORLDBRIDGER"; break;
     	case "187":	$translation = "BLUE-OVERTONE-HAND"; break;
     	case "188":	$translation = "YELLOW-RHYTHMIC-STAR"; break;
     	case "189":	$translation = "RED-RESONANT-MOON"; break;
     	case "190":	$translation = "WHITE-GALACTIC-DOG"; break;
     	case "191":	$translation = "BLUE-SOLAR-MONKEY"; break;
     	case "192":	$translation = "YELLOW-PLANETARY-HUMAN"; break;
     	case "193":	$translation = "RED-SPECTRAL-SKYWALKER"; break;
     	case "194":	$translation = "WHITE-CRYSTAL-WIZARD"; break;
     	case "195":	$translation = "BLUE-COSMIC-EAGLE"; break;
     	case "196":	$translation = "YELLOW-MAGNETIC-WARRIOR"; break;
     	case "197":	$translation = "RED-LUNAR-EARTH"; break;
     	case "198":	$translation = "WHITE-ELECTRIC-MIRROR"; break;
     	case "199":	$translation = "BLUE-SELF-EXISTING-STORM"; break;
     	case "200":	$translation = "YELLOW-OVERTONE-SUN"; break;
     	case "201":	$translation = "RED-RHYTHMIC-DRAGON"; break;
     	case "202":	$translation = "WHITE-RESONANT-WIND"; break;
     	case "203":	$translation = "BLUE-GALACTIC-NIGHT"; break;
     	case "204":	$translation = "YELLOW-SOLAR-SEED"; break;
     	case "205":	$translation = "RED-PLANETARY-SERPENT"; break;
     	case "206":	$translation = "WHITE-SPECTRAL-WORLDBRIDGER"; break;
     	case "207":	$translation = "BLUE-CRYSTAL-HAND"; break;
     	case "208":	$translation = "YELLOW-COSMIC-STAR"; break;
     	case "209":	$translation = "RED-MAGNETIC-MOON"; break;
     	case "210":	$translation = "WHITE-LUNAR-DOG"; break;
     	case "211":	$translation = "BLUE-ELECTRIC-MONKEY"; break;
     	case "212":	$translation = "YELLOW-SELF-EXISTING-HUMAN"; break;
     	case "213":	$translation = "RED-OVERTONE-SKYWALKER"; break;
     	case "214":	$translation = "WHITE-RHYTHMIC-WIZARD"; break;
     	case "215":	$translation = "BLUE-RESONANT-EAGLE"; break;
     	case "216":	$translation = "YELLOW-GALACTIC-WARRIOR"; break;
     	case "217":	$translation = "RED-SOLAR-EARTH"; break;
     	case "218":	$translation = "WHITE-PLANETARY-MIRROR"; break;
     	case "219":	$translation = "BLUE-SPECTRAL-STORM"; break;
     	case "220":	$translation = "YELLOW-CRYSTAL-SUN"; break;
     	case "221":	$translation = "RED-COSMIC-DRAGON"; break;
     	case "222":	$translation = "WHITE-MAGNETIC-WIND"; break;
     	case "223":	$translation = "BLUE-LUNAR-NIGHT"; break;
     	case "224":	$translation = "YELLOW-ELECTRIC-SEED"; break;
     	case "225":	$translation = "RED-SELF-EXISTING-SERPENT"; break;
     	case "226":	$translation = "WHITE-OVERTONE-WORLDBRIDGER"; break;
     	case "227":	$translation = "BLUE-RHYTHMIC-HAND"; break;
     	case "228":	$translation = "YELLOW-RESONANT-STAR"; break;
     	case "229":	$translation = "RED-GALACTIC-MOON"; break;
     	case "230":	$translation = "WHITE-SOLAR-DOG"; break;
     	case "231":	$translation = "BLUE-PLANETARY-MONKEY"; break;
     	case "232":	$translation = "YELLOW-SPECTRAL-HUMAN"; break;
     	case "233":	$translation = "RED-CRYSTAL-SKYWALKER"; break;
     	case "234":	$translation = "WHITE-COSMIC-WIZARD"; break;
     	case "235":	$translation = "BLUE-MAGNETIC-EAGLE"; break;
     	case "236":	$translation = "YELLOW-LUNAR-WARRIOR"; break;
     	case "237":	$translation = "RED-ELECTRIC-EARTH"; break;
     	case "238":	$translation = "WHITE-SELF-EXISTING-MIRROR"; break;
     	case "239":	$translation = "BLUE-OVERTONE-STORM"; break;
     	case "240":	$translation = "YELLOW-RHYTHMIC-SUN"; break;
     	case "241":	$translation = "RED-RESONANT-DRAGON"; break;
     	case "242":	$translation = "WHITE-GALACTIC-WIND"; break;
     	case "243":	$translation = "BLUE-SOLAR-NIGHT"; break;
     	case "244":	$translation = "YELLOW-PLANETARY-SEED"; break;
     	case "245":	$translation = "RED-SPECTRAL-SERPENT"; break;
     	case "246":	$translation = "WHITE-CRYSTAL-WORLDBRIDGER"; break;
     	case "247":	$translation = "BLUE-COSMIC-HAND"; break;
     	case "248":	$translation = "YELLOW-MAGNETIC-STAR"; break;
     	case "249":	$translation = "RED-LUNAR-MOON"; break;
     	case "250":	$translation = "WHITE-ELECTRIC-DOG"; break;
     	case "251":	$translation = "BLUE-SELF-EXISTING-MONKEY"; break;
     	case "252":	$translation = "YELLOW-OVERTONE-HUMAN"; break;
     	case "253":	$translation = "RED-RHYTHMIC-SKYWALKER"; break;
     	case "254":	$translation = "WHITE-RESONANT-WIZARD"; break;
     	case "255":	$translation = "BLUE-GALACTIC-EAGLE"; break;
     	case "256":	$translation = "YELLOW-SOLAR-WARRIOR"; break;
     	case "257":	$translation = "RED-PLANETARY-EARTH"; break;
     	case "258":	$translation = "WHITE-SPECTRAL-MIRROR"; break;
     	case "259":	$translation = "BLUE-CRYSTAL-STORM"; break;
     	case "260":	$translation = "YELLOW-COSMIC-SUN"; break;
	}
	return $translation;
}

// Get the moon phase
function moon_phase($year, $month, $day){
/*
modified from http://www.voidware.com/moon_phase.htm
Found at: http://jivebay.com/2008/09/07/calculating-the-moon-phase/
*/
	$c = $e = $jd = $b = 0;
	if ($month < 3){
		$year--;
		$month += 12;
	}
	++$month;
	$c = 365.25 * $year;
	$e = 30.6 * $month;
	$jd = $c + $e + $day - 694039.09; //jd is total days elapsed
	$jd /= 29.5305882; //divide by the moon cycle
	$b = (int) $jd; //int(jd) -> b, take integer part of jd
	$jd -= $b; //subtract integer part to leave fractional part of original jd
	$b = round($jd * 8); //scale fraction from 0-8 and round
	if ($b >= 8 ){
		$b = 0;//0 and 8 are the same so turn 8 into 0
	}
	switch ($b){
		case 0: return 'New Moon'; break;
		case 1: return 'Waxing Crescent'; break;
		case 2: return 'First Quarter'; break;
		case 3: return 'Waxing Gibbous'; break;
		case 4: return 'Full Moon'; break;
		case 5: return 'Waning Gibbous'; break;
		case 6: return 'Last Quarter'; break;
		case 7: return 'Waning Crescent'; break;
		default: return 'Date out of Range';
	}
}

// prof_to_list
function prof_to_list($Prof){

     // Make array of this event's professions
     $ev_prof_array = str_split($Prof);

     // Create array for professions
     $prof_array 	= array('M', 'E', 'P', 'W', 'A', 'R', 'S', 'Y', 'D', 'T', 'N', 'B', 'U');
     $display_array = array('Music', 'Entertainment', 'Politics', 'Writing', 'Art', 'Religion', 'Science', 'War', 'Sports', 'Education', 'Nature', 'Business', 'Accident');
     
     // Loop through Professions
     $inc_prof = 0;
     foreach($prof_array as $this_prof){
// Which ones should be checked?
     	foreach ($ev_prof_array as $this_ev_prof){
     		if ($this_prof === $this_ev_prof){
     			$profession_list .= $display_array["$inc_prof"].", ";
     		}
     	}
    	$inc_prof++;
	}
    return $profession_list;
}

// Determine if this kin is a portal, and what kind F or P
function is_portal($kin_ID){
	$portal = "N";
	switch ($kin_ID){
		case 1: 			$portal = "P"; break;
		case 20: 			$portal = "P"; break;
		case 22: 			$portal = "P"; break;
		case 39: 			$portal = "P"; break;
		case 43: 			$portal = "P"; break;
		case 50: 			$portal = "F"; break;
		case 51: 			$portal = "F"; break;
		case 58: 			$portal = "P"; break;
		case 64: 			$portal = "P"; break;
		case 69: 			$portal = "F"; break;
		case 72: 			$portal = "F"; break;
		case 77: 			$portal = "P"; break;
		case 85: 			$portal = "P"; break;
		case 88: 			$portal = "F"; break;
		case 93: 			$portal = "F"; break;
		case 96: 			$portal = "P"; break;
		case 106: 		$portal = "P"; break;
		case 107: 		$portal = "F"; break;
		case 108: 		$portal = "P"; break;
		case 109: 		$portal = "P"; break;
		case 110: 		$portal = "P"; break;
		case 111: 		$portal = "P"; break;
		case 112: 		$portal = "P"; break;
		case 113: 		$portal = "P"; break;
		case 114: 		$portal = "F"; break;
		case 115: 		$portal = "P"; break;
		case 146: 		$portal = "F"; break;
		case 147: 		$portal = "P"; break;
		case 148: 		$portal = "F"; break;
		case 149: 		$portal = "F"; break;
		case 150: 		$portal = "F"; break;
		case 151: 		$portal = "F"; break;
		case 152: 		$portal = "F"; break;
		case 153: 		$portal = "F"; break;
		case 154: 		$portal = "P"; break;
		case 155: 		$portal = "F"; break;
		case 165: 		$portal = "F"; break;
		case 168: 		$portal = "P"; break;
		case 173: 		$portal = "P"; break;
		case 176: 		$portal = "F"; break;
		case 184: 		$portal = "F"; break;
		case 189: 		$portal = "P"; break;
		case 192: 		$portal = "P"; break;
		case 197: 		$portal = "F"; break;
		case 203: 		$portal = "F"; break;
		case 210: 		$portal = "P"; break;
		case 211: 		$portal = "P"; break;
		case 218: 		$portal = "F"; break;
		case 222: 		$portal = "F"; break;
		case 239: 		$portal = "F"; break;
		case 241: 		$portal = "F"; break;
		case 260: 		$portal = "F"; break;
    }
	return $portal;
}


// Day Number of Plasma
function tm_day_num_to_plasma_num ($this_day_count){
	switch ($this_day_count) {

     	case "1":		$this_plasma = "1"; break; 
     	case "2":		$this_plasma = "2"; break; 
     	case "3":		$this_plasma = "3"; break; 
     	case "4":		$this_plasma = "4"; break; 
     	case "5":		$this_plasma = "5"; break; 
     	case "6":		$this_plasma = "6"; break; 
     	case "7":		$this_plasma = "7"; break; 
     	case "8":		$this_plasma = "1"; break; 
     	case "9":		$this_plasma = "2"; break; 
     	case "10":	$this_plasma = "3"; break; 
     	case "11":	$this_plasma = "4"; break; 
     	case "12":	$this_plasma = "5"; break; 
     	case "13":	$this_plasma = "6"; break; 
     	case "14":	$this_plasma = "7"; break; 
     	case "15":	$this_plasma = "1"; break; 
     	case "16":	$this_plasma = "2"; break; 
     	case "17":	$this_plasma = "3"; break; 
     	case "18":	$this_plasma = "4"; break; 
     	case "19":	$this_plasma = "5"; break; 
     	case "20":	$this_plasma = "6"; break; 
     	case "21":	$this_plasma = "7"; break; 
     	case "22":	$this_plasma = "1"; break; 
     	case "23":	$this_plasma = "2"; break; 
     	case "24":	$this_plasma = "3"; break; 
     	case "25":	$this_plasma = "4"; break; 
     	case "26":	$this_plasma = "5"; break; 
     	case "27":	$this_plasma = "6"; break; 
     	case "28":	$this_plasma = "7"; break; 
	}
    return $this_plasma;
}

// Day Number of Plasma
function tribe_num_to_tribe_essences_del ($tribe_num){
	switch ($tribe_num) {
     	case "1":		$tribe_essences_del = "|1|Dragon|Nurture|Being|Birth|"; break; 
     	case "2":		$tribe_essences_del = "|2|Wind|Communicate|Breath|Spirit|"; break; 
     	case "3":		$tribe_essences_del = "|3|Night|Dream|Intuition|Abundance|"; break; 
     	case "4":		$tribe_essences_del = "|4|Seed|Target|Awareness|Flowering|"; break; 
     	case "5":		$tribe_essences_del = "|5|Serpent|Survive|Instinct|Life Force|"; break; 
     	case "6":		$tribe_essences_del = "|6|World-Bridger|Equalize|Opportunity|Death|"; break; 
     	case "7":		$tribe_essences_del = "|7|Hand|Know|Healing|Accomplishment|"; break; 
     	case "8":		$tribe_essences_del = "|8|Star|Beautify|Art|Elegance|"; break; 
     	case "9":		$tribe_essences_del = "|9|Moon|Purify|Flow|Universal Water|"; break; 
     	case "10":	$tribe_essences_del = "|10|Dog|Love|Loyalty|Heart|"; break; 
     	case "11":	$tribe_essences_del = "|11|Monkey|Play|Illusion|Magic|"; break; 
     	case "12":	$tribe_essences_del = "|12|Human|Influence|Wisdom|Free Will|"; break; 
     	case "13":	$tribe_essences_del = "|13|Skywalker|Explore|Wakefulness|Space|"; break; 
     	case "14":	$tribe_essences_del = "|14|Wizard|Enchant|Receptivity|Timelessness|"; break; 
     	case "15":	$tribe_essences_del = "|15|Eagle|Create|Mind|Vision|"; break; 
     	case "16":	$tribe_essences_del = "|16|Warrior|Question|Fearlessness|Intelligence|"; break; 
     	case "17":	$tribe_essences_del = "|17|Earth|Evolve|Syncronicity|Navigation|"; break; 
     	case "18":	$tribe_essences_del = "|18|Mirror|Reflect|Order|Endlessness|"; break; 
     	case "19":	$tribe_essences_del = "|19|Storm|Catalyze|Energy|Self-Generation|"; break; 
     	case "20":	$tribe_essences_del = "|20|Sun|Enlighten|Life|Universal Fire|"; break; 
	}
    return $tribe_essences_del;
}

// Day Number of Plasma
function tone_num_to_tone_essences_del ($tone_num){
	switch ($tone_num) {
     	case "1":		$tone_essences_del = "|MAGNETIC|Unify|Attract|Purpose|"; break; 
     	case "2":		$tone_essences_del = "|LUNAR|Polarize|Stabilize|Challenge|"; break; 
     	case "3":		$tone_essences_del = "|ELECTRIC|Activate|Bond|Service|"; break; 
     	case "4":		$tone_essences_del = "|SELF-EXISTING|Define|Measure|Form|"; break; 
     	case "5":		$tone_essences_del = "|OVERTONE|Empower|Command|Radiance|"; break; 
     	case "6":		$tone_essences_del = "|RHYTHMIC|Organize|Balance|Equality|"; break; 
     	case "7":		$tone_essences_del = "|RESONANT|Channel|Inspire|Attunement|"; break; 
     	case "8":		$tone_essences_del = "|GALACTIC|Harmonize|Model|Integrity|"; break; 
     	case "9":		$tone_essences_del = "|SOLAR|Pulse|Realize|Intention|"; break; 
     	case "10":	$tone_essences_del = "|PLANETARY|Perfect|Produce|Manifestation|"; break; 
     	case "11":	$tone_essences_del = "|SPECTRAL|Dissolve|Release|Liberation|"; break; 
     	case "12":	$tone_essences_del = "|CRYSTAL|Dedicate|Universalize|Cooperation|"; break; 
     	case "13":	$tone_essences_del = "|COSMIC|Endure|Transcend|Presence|"; break; 
	}
    return $tone_essences_del;
}

function tmc_castle_num_to_name($castle_number){
	switch ($castle_number) {
     	case "1":		$castle_name = "Red Eastern Castle of Turning"; break; 
     	case "2":		$castle_name = "White Northern Castle of Crossing"; break; 
     	case "3":		$castle_name = "Blue Western Castle of Burning"; break; 
     	case "4":		$castle_name = "Yellow Southern Castle of Giving"; break; 
     	case "5":		$castle_name = "Green Central Castle of Enchantment"; break; 
	}
    return $castle_name;
}

function tmc_wavespell_num_to_name($wavespell_number){
	switch ($wavespell_number) {
     	case "1":		$wavespell_name = "Red Dragon"; break; 
     	case "2":		$wavespell_name = "White Wizard"; break; 
     	case "3":		$wavespell_name = "Blue Hand"; break; 
     	case "4":		$wavespell_name = "Yellow Sun"; break; 
     	case "5":		$wavespell_name = "Red Skywalker"; break; 
     	case "6":		$wavespell_name = "White Worldbridger"; break; 
     	case "7":		$wavespell_name = "Blue Storm"; break; 
     	case "8":		$wavespell_name = "Yellow Human"; break; 
     	case "9":		$wavespell_name = "Red Serpent"; break; 
     	case "10":		$wavespell_name = "White Mirror"; break; 
     	case "12":		$wavespell_name = "Blue Monkey"; break; 
     	case "12":		$wavespell_name = "Yellow Seed"; break; 
     	case "13":		$wavespell_name = "Red Earth"; break; 
     	case "14":		$wavespell_name = "White Dog"; break; 
     	case "15":		$wavespell_name = "Blue Night"; break; 
     	case "16":		$wavespell_name = "Yellow Warrior"; break; 
     	case "17":		$wavespell_name = "Red Moon"; break; 
     	case "18":		$wavespell_name = "White Wind"; break; 
     	case "19":		$wavespell_name = "Blue Eagle"; break; 
     	case "20":		$wavespell_name = "Yellow Star"; break; 
	}
    return $wavespell_name;
}


// This is a WP custom function to get the posts on a given date
function get_this_day_wp_posts($this_mysql_date){
// Break up date for functions
	$this_mysql_date_pieces = explode("-", $this_mysql_date);

     $this_wp_year = $this_mysql_date_pieces[0];
     $this_wp_mon = $this_mysql_date_pieces[1];
     $this_wp_day = $this_mysql_date_pieces[2];

// Prepare the date string to query the db
     if (strlen($this_wp_mon) === 1){$this_wp_mon = "0".$this_wp_mon;}
     if (strlen($this_wp_day) === 1){$this_wp_day = "0".$this_wp_day;}

	$new_wp_mysql_date_today = "$this_wp_year-$this_wp_mon-$this_wp_day";

// We're going to access the database, so we need to globaliza $wpdb
	global $wpdb;

// Query the databazse using WordPress to get a list of posts on this date

// This works
     $thisday_posts_array = $wpdb->get_results("
     SELECT ID, post_title, post_date, guid 
     FROM $wpdb->posts 
     WHERE post_status = 'publish' 
     AND post_type='post' 
     AND (post_date BETWEEN '$new_wp_mysql_date_today 00:00:00' AND '$new_wp_mysql_date_today 23:59:59')
     ORDER BY post_date DESC LIMIT 0,10
     ");

// Try a join to get the name of the poster

/*
     $thisday_posts_array = $wpdb->get_results("
	SELECT post_author, display_name, ID, post_title, post_date, guid 
     FROM $wpdb->posts 
	LEFT JOIN $wpdb->users ON $wpdb->posts.post_author = $wpdb->users.ID 
     WHERE post_status = 'publish' 
     AND post_type='post' 
     AND (post_date BETWEEN '$new_wp_mysql_date_today 00:00:00' AND '$new_wp_mysql_date_today 23:59:59')
     ORDER BY post_date DESC LIMIT 0,10
     ");
*/
	return $thisday_posts_array;
// return $thisday_posts_array;
}

?>