<?php // cal_build_cal_table.inc

// Set defaults on what appears on first load
// Build the calendar

// Change Locale, as needed // What language are you using?
$ucd_locale = get_locale();

// Setlocale
if ($ucd_locale == "es_ES"){setlocale(LC_ALL, 'es_ES');}
elseif ($ucd_locale == "nl_NL"){setlocale(LC_ALL, 'nl_NL');}
else {$ucd_locale = "en_EN"; setlocale(LC_ALL, 'en_EN');}

// Decode the requested Gregorian date: returns: $hilite_kin_num
$hilite_kin_num = tmc_date_mysql_to_kin($mysql_date, $dcode_bcad);

// WE HAVE ALL WE NEED TO CREATE THE 13-MOON SOLAR CYCLE =====================
// Make a function that creates an array of dates & moons for every day of the 13-moon solar cycle - given a MySQL date
// Here's our magic code... it returns an array with 364 items // starting with:             [0] => 1--1--1--2009-7-26
// ending with:             [363] => 364--28--13--2010-7-24 // Call the new array
$array_moons_dates = ms_date_moon_array($dcode_mo, $dcode_day, $dcode_yr);

// Set default moon, in order to correct error... on dates from Jul 27 - Aug 22
$this_moon_num = 1;
$matched = "NO";

// Setup the month arrays
include(dirname(__FILE__).'/cal_setup_month_arrays.inc');

// Get Moon Name, begin day num, end day num
// $this_moon_name = tmc_tone_num_to_name($this_moon_num);

// Create cal_display  -----------------------------------------------------------

$cal_display = "<table id=\"cal_grid\">\n";
$cal_display .= "<tr>\n";

// Get all the days
// Rows and cols of calendar table
// Loop through array of months

// Set starting values
$day_count = 1;
$day_of_mo_num = 1;
$wk_count = 1;

foreach ($array_moons_dates[$this_moon_num] as $moon_date_item){

	$exploded_moon_date = explode("--", $moon_date_item);
	$this_mysql_date = $exploded_moon_date[1];

// Break up date for functions
	$this_date_pcs = explode("-", $this_mysql_date);

// Check to see if this day is LEAP DAY
	$leap_day_info = "";
	
	
     $this_mysql_date_pieces = explode("-", $this_mysql_date);
     if (($this_mysql_date_pieces[1] == 3)&&($this_mysql_date_pieces[2] == 1)){
     	$prior_yr  = $this_mysql_date_pieces[0];
     	$prior_mysql_date_ckld = $this_mysql_date_pieces[0]."-02-29";
	if (ms_date_is_leapday($prior_mysql_date_ckld) === "TRUE"){
	// Adjust back one kin for leap day -- we're going to skip right over it.
 	        	$day_count++;
	// This is leap day, we make a special Linke to a Popup for it
//			$leap_day_info = "<a href=\"$ajax_info?height=250&width=400&date=$prior_mysql_date_ckld&purl=".plugins_url()."\" title=\"$prior_mysql_date_ckld is Leap Day\" class=\"thickbox\">LEAP</a><br>";

			$leap_day_info = "<a href=\"$ajax_info?&date=$prior_mysql_date_ckld&purl=".plugins_url()."\" title=\"$prior_mysql_date_ckld is Leap Day\" class=\"thickbox\">LEAP</a><br>";
			
			// For testing
//			$leap_day_info  .= "$this_mysql_date_pieces[0] $this_mysql_date_pieces[1] $this_mysql_date_pieces[2]";


     	}
     } // End if it's leap day

// Create new row
	if (($day_count == 8)||($day_count == 15)||($day_count == 22)){
		$cal_display .= "</tr>\n";
		$cal_display .= "<tr>";
		$wk_count++;
	} elseif ($day_count == 1){
// START the DAY's row
//		$cal_display .= "<tr>";
	}


// Get Greg date 
// Use adodb for a special timestamp
// adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
	//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// echo "$this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]";

// echo "$this_nice_date";

// Let's get the date
     $this_day_year = $this_date_pcs[0];
     $this_day_mon = $this_date_pcs[1];
     $this_day_day = $this_date_pcs[2];

// Display Nice Date
// Uses locale() above
     if (($this_date_pcs[0] >= 1902)&&($this_date_pcs[0] <= 2037)){
// strtotime() has a range limit between Fri, 13 Dec 1901 20:45:54 GMT and Tue, 19 Jan 2038 03:14:07 GMT
     	$this_nice_translated_date = utf8_encode(strftime("%A %e %B %Y", strtotime("$this_day_mon/$this_day_day/$this_day_year")));
	} else {
		$this_nice_translated_date = $this_nice_date;
	}



// Get the kin number for the day
	$this_day_kin_num = tmc_date_mysql_to_kin($this_mysql_date, $dcode_bcad);

// Change some calculations if it is LEAP YEAR, AND ON OR AFTER 2-28
	if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it once
	if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it again

$cal_class = "norm";
$style_for_hilite_day = "";
// CREATE THE CELL FOR TODAY ====================================
// This is the day requested... highlight it, and get info from db
	if ($this_day_kin_num === $hilite_kin_num){
		$cal_class = "hlt";
		$color_for_hilite_day = get_option('curr_day_hilite_color');
		$style_for_hilite_day = " style=\"background-color: #".$color_for_hilite_day.";\"";
		$this_date_tm_day = $day_count;
		$button_class = "button_today";
		$hightlight_plasma_today = $day_count;
	} else {
		$cal_class = "$wk_count";
		$button_class = "";
	}

// BUTTON 
// If it has posts on this day, we can turn it red like this:
// border-color: fuchsia;
// or this
// font-weight: bold;

// Make a title for the button // 
//	$button_title = 'title="'.$this_nice_translated_date.'-date"';

if (strlen($this_nice_translated_date) < 10) {
	$this_nice_translated_date = $this_nice_date;
}

	$button_title = 'title="'.$this_nice_translated_date.'"';

// Do we have any posts on this day?

     // returns an array: $thisday_posts_array
     $thisday_posts_array = get_this_day_wp_posts($this_mysql_date);

// Set max number of posts to show per day
	$show_num_posts = get_option('show_num_posts');
	if ($show_num_posts == ""){$show_num_posts = 5;}
	// Do we have a listing of POSTS?
	$rurl_enc_posts_del =  "";
	if (count($thisday_posts_array) > 0) {
		$countr = 0;
		foreach ($thisday_posts_array as $thisday_post_item){
	      		if ($countr >= $show_num_posts){
	      			break;
	      		}
	          	$this_id 		= $thisday_post_item->ID;
	          	$this_title 		= $thisday_post_item->post_title;
	          	$this_date 		= $thisday_post_item->post_date;
	          	$this_url 		= $thisday_post_item->guid;
	          	$this_p_auth_nm 	= $thisday_post_item->guid;
			$posts_del		= "$this_url|$this_title|";
	          	$rurl_enc_posts_del .= rawurlencode("$posts_del");
			$countr++;
	          }
	}


     // Use 2 functions to get the correct 13moon date
     $tmc_yrs_since_array = tmc_ns_yr_nums($this_day_year, $this_day_mon, $this_day_day); // returns array of two items: x x
     $tmc_ns_first_cycle = $tmc_yrs_since_array[0];
     $tmc_ns_second_cycle = $tmc_yrs_since_array[1];
     
     // $tmc_ns_first_cycle
     if ($tmc_ns_first_cycle == "-0"){
     	$tmc_ns_first_cycle = str_replace("-", "", "$tmc_ns_first_cycle");
     }
     
     // Create the proper 13-moon date display
     $this_tm_date_proper = "NS".$tmc_ns_first_cycle.".".$tmc_ns_second_cycle.".".$this_moon_num.".".$day_count;

// We build a variable that is the URL that's passed to the ajax jquery program (currently ThickBox, which doesn't allow a POST)
	$ajax_link = $ajax_info;
	$ajax_link .= "?height=300";
	$ajax_link .= "&width=300";
	$ajax_link .= "&date=".$this_mysql_date;
	$ajax_link .= "&purl=".plugins_url();
	$ajax_link .= "&ucd_locale=".$ucd_locale;
	$ajax_link .= "&show_famous_events=".get_option('show_famous_events');
	$ajax_link .= "&rurl_enc_posts_del=".$rurl_enc_posts_del;
	$ajax_link .= "&tm_date_proper=".$this_tm_date_proper;
	


// Get user settings
     $day_with_posts_highlight_border_color = get_option('day_with_posts_highlight_border_color');

// Set defaults
	if ($day_with_posts_highlight_border_color != ""){} else {
		$day_with_posts_highlight_border_color = "f4f";
	}

// Color the cell with more than zero posts
	if (count($thisday_posts_array) > 0) {
		$day_button_style = 'color: #'.$day_with_posts_highlight_border_color.'; border-color: #'.$day_with_posts_highlight_border_color.'; font-weight: bold; border-width: 2px;';
	} else {
		$day_button_style = "";
	}

// tm_date_proper=NS1.27.8.11title=" "="" class="thickbox" type="button" value="11" style="\&quot;color:" #f4f;="" border-color:="" font-weight:="" bold;="" border-width:="" 2px;"="">

// Create cell to hold this day
	$cal_display .= "<td class=\"cal_row_med_$cal_class\" $style_for_hilite_day>\n";
	$cal_display .= "$leap_day_info";

	// Encode for HTML -- WE NEED TO REPLACE THE & WITH SOMETHING NEW
//	$ajax_link = htmlentities($ajax_link);
//	$ajax_link  = str_replace ('&', '&amp;', $ajax_link);

	$cal_display .= '<input alt="';
	$cal_display .= $ajax_link;
	$cal_display .= '" ';
	$cal_display .= $button_title;
	$cal_display .= ' class="thickbox" type="button" value="';
	$cal_display .= $day_count;
	$cal_display .= '" style="';
	$cal_display .= $day_button_style;
	$cal_display .= '">';



// Let's get the date
     $this_day_year = $this_mysql_date_pieces[0];
     $this_day_mon = $this_mysql_date_pieces[1];
     $this_day_day = $this_mysql_date_pieces[2];

// Get the plasma for this day
	$this_plasma_num = tm_day_num_to_plasma_num($day_count);
	$this_plasma_name = gday_nam_to_may_name($this_plasma_num);

// Finished creating cell for the day =============================
	$day_count++;
	$day_of_mo_num++;
}

$cal_display .= "</tr>\n";
$cal_display .= "</table>\n";

// END Create scalar with calendar built ----------------------------------------


?>