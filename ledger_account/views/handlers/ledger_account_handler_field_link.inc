<?php

/**
 * Field handler to present a link to an account.
 */
class ledger_account_handler_field_link extends views_handler_field {
  
  // Construct the handler.
  function construct() {
    
    // Inherit the parent's construction.
    parent::construct();
    
    // Add the account id as an additional field to load to ensure that it is available in this handler.
    $this->additional_fields['aid'] = 'aid';
  }
  
  // Define the options.
  function option_definition() {
    
    // Inherit the parent's options.
    $options = parent::option_definition();
    
    // Provide a text field so users can change the text of the link.
    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE
    );
    
    return $options;
  }
  
  // Define the options form.
  function options_form(&$form, &$form_state) {
    
    // Inherit the parent's options form.
    parent::options_form($form, $form_state);
    
    // Provide a text field so users can change the text of the link.
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }
  
  // Add fields to the query.
  function query() {
    
    // Ensure the main table for this field is included.
    $this->ensure_my_table();
    
    // Include additional fields (like account id defined in $this->construct())
    $this->add_additional_fields();
  }
  
  // Render the field.
  function render($values) {
    
    // Load the link text, if it is defined by the user, otherwise just use "view".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    
    // Load the account id value.
    $aid = $this->get_value($values, 'aid');
    
    // Return the text as a link to the account page.
    return l($text, 'admin/ledger/accounts/' . $aid);
  }
}
