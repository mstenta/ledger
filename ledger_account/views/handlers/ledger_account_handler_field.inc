<?php

/**
 * @file
 * Field handler to provide simple renderer that allows linking to an account.
 */
class ledger_account_handler_field extends views_handler_field {

  // Initialize the handler.
  function init(&$view, &$options) {

    // Inherit the parent initialization.
    parent::init($view, $options);

    // If the transaction is going to be linked to it's view page, we need to load the taxonomy id value so it's available to this handler.
    if ($this->options['link_to_account'] == 'view') {
      $this->additional_fields['aid'] = 'aid';
    }
  }

  // Define the options.
  function option_definition() {

    // Inherit the parent option definition.
    $options = parent::option_definition();

    // Add an option for displaying the account as a link to it's view page.
    $options['link_to_account'] = array('default' => 'none');

    return $options;
  }

  // Define the options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent options form.
    parent::options_form($form, $form_state);

    // Add an option for displaying the account as a link to it's view page.
    $form['link_to_account'] = array(
      '#type' => 'radios',
      '#title' => t('Link this field to'),
      '#description' => t('If the account view page is selected, this will override any other links you have set.'),
      '#options' => array(
        'none' => t('Nothing, unless specified in <em>Rewrite results</em> below'),
        'view' => t('The account view page'),
      ),
      '#default_value' => $this->options['link_to_account'],
    );
  }

  // Render the field.
  function render($values) {

    // Load the value.
    $value = $this->get_value($values);

    // Return a rendered link.
    return $this->render_link($this->sanitize_value($value), $values);
  }

  // Render a link.
  function render_link($data, $values) {

    // If the 'link_to_transaction' option is set to 'view', and the sanitized data is not empty...
    if ($this->options['link_to_account'] == 'view' && $data !== NULL && $data !== '') {

      // Load the transaction id.
      $aid = $this->get_value($values, 'aid');

      // Alter the options of the link.
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'admin/ledger/accounts/' . $aid;
    }

    return $data;
  }
}
