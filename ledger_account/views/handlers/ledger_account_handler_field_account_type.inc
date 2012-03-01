<?php

/**
 * @file
 * Field handler to translate a product type into its readable form.
 */
class ledger_account_handler_field_account_type extends views_handler_field {

  // Render the field.
  function render($values) {

    // Load the account type.
    $type = $this->get_value($values);

    // Get the account type label.
    $value = ledger_account_type_label($type);

    // Return the sanitized value.
    return $this->sanitize_value($value);
  }
}
