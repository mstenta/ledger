<?php

/**
 * Field handler to translate a product type into its readable form.
 */
class ledger_account_handler_field_account_type extends views_handler_field {
  function render($values) {
    $type = $this->get_value($values);
    $value = ledger_account_type_label($type);

    return $this->sanitize_value($value);
  }
}
