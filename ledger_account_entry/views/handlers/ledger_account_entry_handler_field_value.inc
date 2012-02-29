<?php

/**
 * @file
 * Contains the account entry value field handler.
 */

/**
 * Field handler to provide more advanced display options of an account entry's
 */
class ledger_account_entry_handler_field_value extends views_handler_field_numeric {

  // Define the options.
  function option_definition() {

    // Inherit the parent option definition.
    $options = parent::option_definition();

    // Add an option for defining how the value should be formatted.
    $options['format'] = array('default' => 'normal');

    return $options;
  }

  // Define the options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent options form.
    parent::options_form($form, $form_state);

    // Add an option for defining how the value should be formatted.
    $form['format'] = array(
      '#type' => 'select',
      '#title' => t('Format this value as'),
      '#description' => t('Provides options for how the value will be displayed.'),
      '#options' => array(
        'normal' => t('Normal - the actual account entry value'),
        'increase' => t('Increase - value increase in the account'),
        'decrease' => t('Decrease - value decrease in the account'),
      ),
      '#default_value' => $this->options['format'],
    );
  }

  // Render the field.
  function render($in_values) {

    // Clone the values so we don't alter them globally.
    $values = clone $in_values;

    // Load a reference to the value.
    $value =& $values->{$this->field_alias};

    // Calculate the in/out values of the account.
    $in = 0;
    $out = 0;
    if ($value > 0) {
      $in = $value;
    }
    elseif ($value < 0) {
      $out = abs($value);
    }

    // If the format option is 'increase' or 'decrease', set the value to what we calculated above.
    switch ($this->options['format']) {
      case 'increase':
        $value = $in;
        break;
      case 'decrease':
        $value = $out;
        break;
    }

    // If the value isn't empty, pass it to the parent render function.
    if (!empty($value)) {
      return parent::render($values);
    }
  }
}