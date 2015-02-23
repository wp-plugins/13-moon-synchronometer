<?php // cal_trans_static.inc  // Translate static text values

// What language are you using?
$ucd_locale = get_locale();

// Check to see if file is there...
if ($ucd_locale == "es_ES"){

	// Spanish Values
	$tr_txt_day_br			= "Dia<br>";		// 20 *
	$tr_txt_tone			= "Tono";		// 21 *
	$tr_txt_amino			= "Aminoácido:";	// 22 *
	$tr_txt_of			= "de";			// 23 *
	$tr_txt_moon			= "luna";		// 24 *
	
	// Oracle additions
	$word_guiding_power 		= "Guiding Power";
	$word_analog 			= "Analog";
	$word_occult 			= "Occult";
	$word_antipode 			= "Antipode";

} elseif ($ucd_locale == "nl_NL"){

	$tr_txt_day_br			= "Dag<br>";   	// 20 *
	$tr_txt_tone			= "Toon";        // 21 *
	$tr_txt_amino			= "Aminozuur:";	// 22 *
	$tr_txt_of			= "van";	// 23 *
	$tr_txt_moon			= "maan";	// 24 *
	
	// Oracle additions
	$word_guiding_power 		= "Guiding Power";
	$word_analog 			= "Analog";
	$word_occult 			= "Occult";
	$word_antipode 			= "Antipode";

} else {

	// English Values
	$tr_txt_day_br			= "Day<br>";		// 20 *
	$tr_txt_tone			= "Tone";		// 21 *
	$tr_txt_amino			= "Amino Acid:";	// 22 *
	$tr_txt_of			= "of";			// 23 *
	$tr_txt_moon			= "moon";		// 24 *
	
	// Oracle additions
	$word_guiding_power 		= "Guiding Power";
	$word_analog 			= "Analog";
	$word_occult 			= "Occult";
	$word_antipode 			= "Antipode";
}

// Encode the special Characters with // utf8_encode(}
$tr_txt_day_br			= utf8_encode($tr_txt_day_br); // encode itDia<br>";		// 20 *
$tr_txt_tone			= utf8_encode($tr_txt_tone); // encode itTono";			// 21 *
$tr_txt_amino			= utf8_encode($tr_txt_amino); // encode itAminoácido:";		// 22 *
$tr_txt_of			= utf8_encode($tr_txt_of); // encode itde";			// 23 *
$tr_txt_moon			= utf8_encode($tr_txt_moon); // encode itde";			// 24 *

?>