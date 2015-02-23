<?php // wavespell_for_widget.inc CALLED BY: tm_wavespell_construct.inc
// ORIGINALY: kin_wavespell.inc ON SSP

$mp_thisfile[] = "wavespell_for_widget.inc";



// Retrieve a setting and set the highligted cell color
$highlight_style = ' style="background-color: #'.$this_kin_bg_color_hex.';"';

// Wavespell needs a starting kin... 
$tone_num	= $kin_line_array[$this_day_kin_num][5];
$wavespell_kin	= tmc_kin_to_wavespell($this_day_kin_num, $tone_num);

// Wavespell needs a starting tribe 
$wsTribeNum		= $kin_line_array[$wavespell_kin][10];
$wsTribeNameMixed 	= $kin_line_array[$wsTribeNum][11];

// Setup new array with 13 items
for ($x = 0; $x <= 12; $x++) {

// Do some processing
	$this_tone_num = ($x + 1);
	$this_kin = ($wavespell_kin + $x);
	$this_tribe_num = ($wsTribeNum + $x);
	if ($this_tribe_num > 20){$this_tribe_num = ($this_tribe_num - 20);}

// Create the tone img
	$the_word_tone = $txt_26;
	$this_tone_name = $kin_line_array[$this_tone_num][6];
	if (strlen($this_tone_num) === 1){$tone_img_name = '0'.$this_tone_num.'.png';} else {$tone_img_name = $this_tone_num.'.png';}
	$img_attrib_extra = $the_word_tone.' '.$this_tone_num.' '.$this_tone_name;
	$tone_img  = '<img src="'.$top_tones_img_dir.'/'.$tone_img_name.'" alt="'.$img_attrib_extra.'" title="'.$img_attrib_extra.'">';

// Create the seal img
	$the_word_seal = $txt_27;
	$this_tribe_name = $kin_line_array[$this_tribe_num][11];
	$kin_line_array[$this_day_kin_num][11];
	if (strlen($this_tribe_num) === 1){$seal_img_name = '0'.$this_tribe_num.'.png';} else {$seal_img_name = $this_tribe_num.'.png';}
	$img_attrib_extra = $the_word_seal.' '.$this_tribe_num.' '.$this_tribe_name;
	$seal_img  = '<img src="'.$seals_img_dir.'/'.$seal_img_name.'" alt="'.$img_attrib_extra.'" title="'.$img_attrib_extra.'">';

// Create a highlighted day
	if ($this_day_kin_num === $this_kin){$this_div_style = $highlight_style;} else {$this_div_style = '';}

	$ws_img_pkg = "";
	$ws_img_pkg .= '<div class="tone_seal_container"'.$this_div_style.'>';
	$ws_img_pkg .= '<div class="ws_tone_img">';
	$ws_img_pkg .= "$tone_img";
	$ws_img_pkg .= '</div>';
	$ws_img_pkg .= '<div class="ws_seal_img">';
	$ws_img_pkg .= "$seal_img";
	$ws_img_pkg .= '</div>';
	$ws_img_pkg .= '</div>';

// ASSIGN: kin_id, tone_num, tribe_num, 
	$ws_info[$x] = array(
		"kin_id" => "$this_kin",
		"tone_num" => ($x + 1),
		"tribe_num" => "$this_tribe_num", 
		"ws_img_pkg" => "$ws_img_pkg", 
	);
} // END for loop


// Create the Wavespell Table
$ocx = '';
$ocx .= '<div id=\'wavespell_id\' class=\'wavespell_class\'>'; // Create a div for the table
$ocx .= '<table  cellpadding=0 cellspacing=0>'; // Main Table

// Row 1 ---------------------------------------------
$ocx .= '<tr>';
// cell for TONE 1
	$ocx .= '<td>';
	$ocx .= $ws_info[0]['ws_img_pkg']; // Tone 1
	$ocx .= '</td>';
$ocx .= '<td colspan=4></td>';
$ocx .= '</tr>';

// Row 2 -------------------------------------------
$ocx .= '<tr>';
// cell for TONE 2 
	$ocx .= '<td>';
	$ocx .= $ws_info[1]['ws_img_pkg']; // Tone 2
	$ocx .= '</td>';
$ocx .= '<td colspan=2></td>';

// cell for TONE 13
	$ocx .= "<td>";
	$ocx .= $ws_info[12]['ws_img_pkg']; // Tone 13
	$ocx .= '</td>';

// cell for TONE 12
	$ocx .= "<td>";
	$ocx .= $ws_info[11]['ws_img_pkg']; // Tone 12
	$ocx .= '</td>';
$ocx .= "</tr>\n";

// Row 3 -------------------------------------------
// cell for TONE 3
$ocx .= "<tr>\n";
	$ocx .= "<td>";
	$ocx .= $ws_info[2]['ws_img_pkg']; // Tone 3
	$ocx .= '</td>';
$ocx .= "<td colspan=3></td>\n";

// cell for TONE 11
	$ocx .= "<td>";
	$ocx .= $ws_info[10]['ws_img_pkg']; // Tone 11
	$ocx .= "</td>\n";
$ocx .= "</tr>\n";

// Row 4 -------------------------------------------
$ocx .= "<tr>\n";
	$ocx .= "<td>";
	$ocx .= $ws_info[3]['ws_img_pkg']; // Tone 4
	$ocx .= "</td>\n";
$ocx .= "<td colspan=3></td>\n";

// cell for TONE 10
	$ocx .= "<td>";
	$ocx .= $ws_info[9]['ws_img_pkg']; // Tone 10
	$ocx .= "</td>\n";
$ocx .= "</tr>\n";

// Row 5 -------------------------------------------
$ocx .= "<tr>\n";
// cell for TONE 5
	$ocx .= "<td>";
	$ocx .= $ws_info[4]['ws_img_pkg']; // Tone 5
	$ocx .= "</td>\n";

// cell for TONE 6
	$ocx .= "<td>";
	$ocx .= $ws_info[5]['ws_img_pkg']; // Tone 6
	$ocx .= "</td>\n";

// cell for TONE 7
	$ocx .= "<td>";
	$ocx .= $ws_info[6]['ws_img_pkg']; // Tone 7
	$ocx .= "</td>\n";

// cell for TONE 8
	$ocx .= "<td>";
	$ocx .= $ws_info[7]['ws_img_pkg']; // Tone 8
	$ocx .= "</td>\n";

// cell for TONE 9
	$ocx .= "<td>";
	$ocx .= $ws_info[8]['ws_img_pkg']; // Tone 9
	$ocx .= "</td>\n";

// End final row
$ocx .= "</tr>\n";
// End table
$ocx .= "</table>\n"; // END Main Table

$ocx .= "</div>\n"; // END div for the table


echo "$ocx";

?>