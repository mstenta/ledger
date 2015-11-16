<?php

/**
 * @file
 * Contains the account entry value field handler.
 */

/**
 * Field handler to provide more advanced display options of an account entry's value.
 */
class ledger_handler_field_value extends fraction_handler_field_field {

  /**
   * Define the options.
   */
  function option_definition() {

    // Inherit the parent option definition.
    $options = parent::option_definition();

    // Add an option for defining how the value should be formatted.
    $options['condition'] = array('default' => 'normal');

    return $options;
  }

  /**
   * Define the options form.
   */
  function options_form(&$form, &$form_state) {

    // Inherit the parent options form.
    parent::options_form($form, $form_state);

    // Option to define a condition for displaying the value.
    $form['condition'] = array(
      '#type' => 'select',
      '#title' => t('Conditional display'),
      '#description' => t('Under what conditions should the value be displayed?'),
      '#options' => array(
        'normal' => t('Always show the value'),
        'increase' => t('Only show a net increase value'),
        'decrease' => t('Only show a net decrease value'),
      ),
      '#default_value' => $this->options['condition'],
    );
  }

  /**
   * Render the item.
   */
  function render_item($count, $item) {

    // If the condition is 'normal', simply return the rendered item.
    if ($this->options['condition'] == 'normal') {
      return render($item['rendered']);
    }

    // If the numerator is empty, return nothing.
    if (empty($item['raw']['numerator'])) {
      return;
    }

    // Determine if the value is positive.
    $positive = ($item['raw']['numerator'] > 0);

    // Remove the minus sign from negative numbers.
    if (!$positive) {
      $item['rendered']['#markup'] = str_replace('-', '', $item['rendered']['#markup']);
    }

    // Hide values where the condition and positive values don't match.
    if (($this->options['condition'] == 'increase' && !$positive) || ($this->options['condition'] == 'decrease' && $positive)) {
      $item['rendered']['#markup'] = '';
    }

    // Return the rendered item.
    return render($item['rendered']);
  }
}

