<?php // prep_for_kin.inc CALLED BY: tm_*_construct.inc


// Check the Language....
// What language are you using? // $ucd_locale = get_locale();
if ($ucd_locale == "es_ES"){$file_fun_lang_ext = "_es";} elseif ($ucd_locale == "nl_NL"){$file_fun_lang_ext = "_nl";} else {$file_fun_lang_ext = "_en";}

// Choose the correct file // To avoid database query, we simply load the output of the kin table into an array
// Get a file into an array.  In this example we'll go through HTTP to get
$lines = file(dirname(__FILE__).'/kin_lookup'.$file_fun_lang_ext.'.txt'); // read into array $lines[]
$inc = 0;
foreach ($lines as $kin_line){
	$kin_line_array[$inc] = explode("|", $kin_line);
	$inc ++;
}

// Get the kin number for the day
$this_day_kin_num = tmc_date_mysql_to_kin($this_mysql_date, $dcode_bcad);

// Change some calculations if it is LEAP YEAR, AND ON OR AFTER 2-28
if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it once
if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it again

// Get Greg date  // Use adodb for a special timestamp // adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Instead of a database, we use an array made from the file kin_lookup.txt // There are 18 columns
// It relies on the second line being numbered 1 to 260, in order with the Kin Number 

// The first line is some standard text in the language provided
$txt_zero		= $kin_line_array[0][0];
$txt_two		= $kin_line_array[0][2];
$txt_four		= $kin_line_array[0][4];
$txt_five		= $kin_line_array[0][5];
$txt_six		= $kin_line_array[0][6];
$txt_eight		= $kin_line_array[0][8];
$txt_ten		= $kin_line_array[0][10];
$txt_twelve		= $kin_line_array[0][12];
$txt_fourteen		= $kin_line_array[0][14];
$txt_sixteen		= $kin_line_array[0][16];
$txt_eighteen		= $kin_line_array[0][18];
$txt_nineteen		= $kin_line_array[0][19];
$txt_twenty		= $kin_line_array[0][20];
$txt_twentyone		= $kin_line_array[0][21];
$txt_twentytwo		= $kin_line_array[0][22];
$txt_twentythree	= $kin_line_array[0][23];
$txt_twentyfour		= $kin_line_array[0][24];
$txt_twentyfive		= $kin_line_array[0][25];

$txt_26			= $kin_line_array[0][26];
$txt_27			= $kin_line_array[0][27];
$txt_28			= $kin_line_array[0][28];

$txt_zero		= utf8_encode($txt_zero);
$txt_two		= utf8_encode($txt_two);
$txt_four		= utf8_encode($txt_four);
$txt_five		= utf8_encode($txt_five);
$txt_six		= utf8_encode($txt_six);
$txt_eight		= utf8_encode($txt_eight);
$txt_ten		= utf8_encode($txt_ten);
$txt_twelve		= utf8_encode($txt_twelve);
$txt_fourteen		= utf8_encode($txt_fourteen);
$txt_sixteen		= utf8_encode($txt_sixteen);
$txt_eighteen		= utf8_encode($txt_eighteen);
$txt_nineteen		= utf8_encode($txt_nineteen); 		// the word: Castle:
$txt_twenty		= utf8_encode($txt_twenty); 		// castle 1
$txt_twentyone		= utf8_encode($txt_twentyone);		// castle 2
$txt_twentytwo		= utf8_encode($txt_twentytwo);		// castle 3
$txt_twentythree	= utf8_encode($txt_twentythree);	// castle 4
$txt_twentyfour		= utf8_encode($txt_twentyfour); 	// castle 5
$txt_twentyfive		= utf8_encode($txt_twentyfive); 	// the word: Wavespell

$txt_26			= utf8_encode($txt_26); 	// the word: Tone
$txt_27			= utf8_encode($txt_27); 	//  the word: Seal
$txt_28			= utf8_encode($txt_28); 	// 


// Each subsequent line is some valuable info
$kin_num		= $kin_line_array[$this_day_kin_num][0];
$castle_num		= $kin_line_array[$this_day_kin_num][1];
$wavespell_num		= $kin_line_array[$this_day_kin_num][2];
$harmonic_num		= $kin_line_array[$this_day_kin_num][3];
$color_name		= $kin_line_array[$this_day_kin_num][4];
$tone_num		= $kin_line_array[$this_day_kin_num][5];
$tone_name		= $kin_line_array[$this_day_kin_num][6];
$tone_cr_pwr		= $kin_line_array[$this_day_kin_num][7];
$tone_action		= $kin_line_array[$this_day_kin_num][8];
$tone_func		= $kin_line_array[$this_day_kin_num][9];
$seal_num		= $kin_line_array[$this_day_kin_num][10];
$seal_name		= $kin_line_array[$this_day_kin_num][11];
$seal_action		= $kin_line_array[$this_day_kin_num][12];
$seal_cr_pwr		= $kin_line_array[$this_day_kin_num][13];
$seal_func		= $kin_line_array[$this_day_kin_num][14];
$timecell		= $kin_line_array[$this_day_kin_num][15];
$guiding_power		= $kin_line_array[$this_day_kin_num][16];
$portals		= $kin_line_array[$this_day_kin_num][17];
$polar_kin		= $kin_line_array[$this_day_kin_num][18];
$earth_family		= $kin_line_array[$this_day_kin_num][19];
$timecell_number	= $kin_line_array[$this_day_kin_num][20];

// $txt_twentysix		= $kin_line_array[0][26]; // Not added yet

$kin_num		=  utf8_encode($kin_num);
$castle_num		=  utf8_encode($castle_num);
$wavespell_num		=  utf8_encode($wavespell_num);
$harmonic_num		=  utf8_encode($harmonic_num);
$color_name		=  utf8_encode($color_name);
$tone_num		=  utf8_encode($tone_num);
$tone_name		=  utf8_encode($tone_name);
$tone_cr_pwr		=  utf8_encode($tone_cr_pwr);
$tone_action		=  utf8_encode($tone_action);
$tone_func		=  utf8_encode($tone_func);
$seal_num		=  utf8_encode($seal_num);
$seal_name		=  utf8_encode($seal_name);
$seal_action		=  utf8_encode($seal_action);
$seal_cr_pwr		=  utf8_encode($seal_cr_pwr);
$seal_func		=  utf8_encode($seal_func);
$timecell		=  utf8_encode($timecell);
$guiding_power		=  utf8_encode($guiding_power);
$portals		=  utf8_encode($portals);
$polar_kin		=  utf8_encode($polar_kin);
$earth_family		=  utf8_encode($earth_family);
$timecell_number	= utf8_encode($timecell_number);


if ($castle_num == 1){$this_castle_affirm = "$txt_nineteen $castle_num: $txt_twenty";}
elseif ($castle_num == 2){$this_castle_affirm = "$txt_nineteen $castle_num: $txt_twentyone";}
elseif ($castle_num == 3){$this_castle_affirm = "$txt_nineteen $castle_num: $txt_twentytwo";}
elseif ($castle_num == 4){$this_castle_affirm = "$txt_nineteen $castle_num: $txt_twentythree";}
else {$this_castle_affirm = "$txt_nineteen $castle_num: $txt_twentyfour";}

// Wavespell Info
$wavespell_kin_num = tmc_kin_to_wavespell($kin_num, $tone_num);

$get_ws_color	= $kin_line_array[$wavespell_kin_num][4]; 	// Blue
$get_ws_seal	= $kin_line_array[$wavespell_kin_num][11]; 	// Hand
$get_ws_color	= utf8_encode($get_ws_color);
$get_ws_seal	= utf8_encode($get_ws_seal);
$this_wavespell_affirm = "$txt_twentyfive $get_ws_color $get_ws_seal";

// Affirmations:
$affirm_one	= "$txt_zero $tone_cr_pwr $txt_two $seal_action"; 	// I	tone_cr_pwr	in order to	seal_action
$affirm_two	= "$txt_four $tone_action $txt_six $seal_cr_pwr";
$affirm_three	= "$txt_eight $timecell $txt_ten $seal_func"; 		// I seal the	timecell	of	seal_func
$affirm_four	= "$txt_twelve $tone_name $txt_fourteen $tone_func"; 	// With the	tone_name	tone of	tone_func
$affirm_five	= "$txt_sixteen $guiding_power"; 			// 
$affirm_six	= "$txt_eighteen"; 					// 

// Get guiding power seal num
$guid_pwr_seal_num = guiding_power($tone_num, $seal_num);

// Get seal graphics for this kin
$seal_image = seal_num_to_img_num($seal_num);
$tone_image = tone_num_to_img_num($tone_num);

// Translate this kin to seo
$this_day_kin_seof = tmc_translate_kin_to_seo($this_day_kin_num);

	

?>