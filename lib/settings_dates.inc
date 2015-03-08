<?php // settings_dates.inc CALLED BY: 
$mp_thisfile[] = "settings_dates.inc";  // get_ns_date CALLED BY: tm_*_construct.inc

// THIS FILE DOES:

	// SET DIRECTORIES FOR ASSETS
	// SET DEFAULT OPTIONS
	// INCLUDE FUNCTIONS
	// Translate a few COMMON terms
	// SET THE START DATEz

// Directory paths for images
$moons_img_dir 		= plugins_url().'/13-moon-synchronometer/images/moons';
$plasmas_img_dir 	= plugins_url().'/13-moon-synchronometer/images/plasmas';
$tones_img_dir 		= plugins_url().'/13-moon-synchronometer/images/tones';
$top_tones_img_dir 	= plugins_url().'/13-moon-synchronometer/images/tones_top';
$seals_img_dir 		= plugins_url().'/13-moon-synchronometer/images/seals';
$portals_img_dir 	= plugins_url().'/13-moon-synchronometer/images/portals';
$img_dir 		= plugins_url().'/13-moon-synchronometer/images';
$ajax_info 		= plugins_url().'/13-moon-synchronometer/ajax_info.php';

// Set defaults
$decode_table_background_color = "#".get_option('decode_table_background_color');
if ($decode_table_background_color == "#"){$decode_table_background_color = "#eee";}

$moon_table_background_color = "#".get_option('moon_table_background_color');
if ($moon_table_background_color == "#"){$moon_table_background_color = "#ddd";}

$plasma_table_background_color = "#".get_option('plasma_table_background_color');
if ($plasma_table_background_color == "#"){$plasma_table_background_color = "#fff";}

// GET OPTIONS
$permit_credits = get_option('permit_credits');

// Using ADOdb Date Time Library -- and only calling once in case the calendar is on the page twice
if (function_exists('adodb_date_test_date')){} else {include(dirname(__FILE__).'/adodb-time.inc.php');}

// Get Functions
if (function_exists('tmc_date_mysql_to_kin')){} else {include(dirname(__FILE__).'/functions.inc');}

// Translate a few COMMON terms
include(dirname(__FILE__).'/cal_trans_static.inc');

// ================= SETTING THE START DATE =========================
// ONLY 4 WAYS ======================================================

// 1) YOU ARRIVE AT A PAGE, AND NEED TODAY'S DATE
// 2) IF THIS IS A POST, AND DATED
// 3) IF THIS IS A DECODING EVENT BY KIN
// 4) IF THIS IS A DECODING EVENT BY DATE
// 5) IF THIS IS A DECODING EVENT BY U-CHING CHAPTER -- WORKING ON THIS

// use today's date	
$dcode_yr 	= adodb_date("Y");
$dcode_mo 	= adodb_date("n");
$dcode_day 	= adodb_date("j");
$dcode_bcad 	= "AD";

// Format for MySQL
$mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
$this_mysql_date = $mysql_date;

// Get the date requested and return properly formatted date 
if (isset($_GET['dcode_yr'])){
	$_GET['dcode_yr'] 	= $_GET['dcode_yr'];
	$_GET['dcode_mo'] 	= ltrim($_GET['dcode_mo'], '0');
	$_GET['dcode_day'] 	= ltrim($_GET['dcode_day'], '0');
	$dcode_bcad 	= "AD";
}

// Is this a WordPress post?
$this_pg_type_post = get_post_type(get_the_ID());
if (($this_pg_type_post == "post")||($this_pg_type_post == "event")){
	$this_post_date = get_the_date("Y-n-j");
	$this_post_date_pcs = explode("-", $this_post_date);
	$dcode_yr  = $this_post_date_pcs[0]; // Y	A full numeric representation of a year, 4 digits
	$dcode_mo  = $this_post_date_pcs[1];  // n	Numeric representation of a month, with NO leading zeros
	$dcode_day = $this_post_date_pcs[2];  // j	Day of the month, 2 digits with leading NO zeros
	$dcode_bcad 	= "AD";
// Format for MySQL
	$mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
	$this_mysql_date = $mysql_date;
}

// 2) IF THIS IS A DECODING EVENT BY KIN

// Using the Kin Decoder
if (isset($_GET['dcode_kin'])){
	$start_kin_id = $_GET['dcode_kin'];
	$next_date_array = tmc_kin_to_next_gb($start_kin_id); // 	return array($next_gb_date_mysql, $days_to_gb);
	$this_new_date = $next_date_array[0];
	$this_date_pcs = explode('-',$this_new_date);
	$dcode_yr = $this_date_pcs[0];
	$dcode_mo = $this_date_pcs[1];
	$dcode_day = $this_date_pcs[2];
	// Correct the gets
	$_GET['dcode_yr'] = $dcode_yr;
	$_GET['dcode_mo'] = $dcode_mo;
	$_GET['dcode_day'] = $dcode_day;
// Format for MySQL
	$mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
	$this_mysql_date = $mysql_date;
}      

// 2) IF THIS IS A DECODING EVENT BY DATE

if (isset($_GET['dcode_mo'])){
// Adjust the dates if either DOOT or LEAP were requested
	if (($_GET['dcode_mo'] == 2) && ($_GET['dcode_day'] > 28)) {$_GET['dcode_day'] = 1;$_GET['dcode_mo'] = 3;}
	if (($_GET['dcode_mo'] == 4) && ($_GET['dcode_day'] > 30)) {$_GET['dcode_day'] = 1;$_GET['dcode_mo'] = 5;}
	if (($_GET['dcode_mo'] == 6) && ($_GET['dcode_day'] > 30)) {$_GET['dcode_day'] = 1;$_GET['dcode_mo'] = 7;}
	if (($_GET['dcode_mo'] == 9) && ($_GET['dcode_day'] > 30)) {$_GET['dcode_day'] = 1;$_GET['dcode_mo'] = 10;}
	if (($_GET['dcode_mo'] == 11) && ($_GET['dcode_day'] > 30)) {$_GET['dcode_day'] = 1;$_GET['dcode_mo'] = 12;}
	
	$dcode_yr	= $_GET['dcode_yr'];
	$dcode_mo	= $_GET['dcode_mo'];
	$dcode_day 	= $_GET['dcode_day'];
	$dcode_bcad 	= "AD";
	
// Format for MySQL
	$mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
	$this_mysql_date = $mysql_date;
}

// Assign to AD if no entry for dcode_bcad
if (($dcode_bcad !== "BC")||($dcode_bcad !== "AD")){
	$dcode_bcad = "AD";
}

// Get the kin number for the day ================================== THE KIN - THE KIN - THE KIN ===================================================
$this_day_kin_num = tmc_date_mysql_to_kin($this_mysql_date, "AD");
// Get the kin number for the day ================================== THE KIN - THE KIN - THE KIN ===================================================

// Change Locale, as needed // What language are you using?
$ucd_locale = get_locale();

// What language are you using? // $ucd_locale = get_locale();
if ($ucd_locale == "es_ES"){$file_fun_lang_ext = "_es";} 
elseif ($ucd_locale == "nl_NL"){$file_fun_lang_ext = "_nl";} 
else {$file_fun_lang_ext = "_en";}

// We can make a pretty date in different languages, but it's not simple
// Break up date for functions
$this_date_pcs = explode("-", $this_mysql_date);

// Use adodb for a special timestamp  // adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Let's get the date
$this_day_year = $this_date_pcs[0];
$this_day_mon = $this_date_pcs[1];
$this_day_day = $this_date_pcs[2];

// Display Nice Date // Uses locale() above // strtotime() has a range limit between Fri, 13 Dec 1901 20:45:54 GMT and Tue, 19 Jan 2038 03:14:07 GMT
if (($this_day_year >= 1902)&&($this_day_year <= 2037)){
	$this_nice_translated_date = utf8_encode(strftime("%A %e %B %Y", strtotime("$this_day_mon/$this_day_day/$this_day_year")));
} else {$this_nice_translated_date = $this_nice_date;}

// Prepare nice Gregorian date
$nice_date = $this_nice_translated_date;

// To avoid database query, we simply load the output of the kin table into an array      // Choose the correct file
$lines = file(dirname(__FILE__).'/kin_lookup'.$file_fun_lang_ext.'.txt'); // read into array $lines[]
$inc = 0;
foreach ($lines as $kin_line){
	$kin_line_array[$inc] = explode("|", $kin_line);
	$inc ++;
}

// Get the converted 13-Moon NS Date
$somvealue = include(dirname(__FILE__).'/get_ns_date.inc');

// Get the translated tone
$this_moon_name	= $kin_line_array[$this_moon_num][6];
$this_moon_name	= utf8_encode($this_moon_name);

?>