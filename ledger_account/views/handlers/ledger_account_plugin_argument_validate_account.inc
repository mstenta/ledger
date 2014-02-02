<?php

/**
 * @file
 * Contains the 'account' argument validator plugin.
 */

/**
 * Validate whether an argument is an acceptable account.
 */
class ledger_account_plugin_argument_validate_account extends views_plugin_argument_validate {
  function option_definition() {
    $options = parent::option_definition();
    $options['access'] = array('default' => FALSE, 'bool' => TRUE);
    $options['access_op'] = array('default' => 'view');
    $options['aid_type'] = array('default' => 'aid');

    return $options;
  }

  function options_form(&$form, &$form_state) {

    $form['access'] = array(
      '#type' => 'checkbox',
      '#title' => t('Validate user has access to the account'),
      '#default_value' => $this->options['access'],
    );
    $form['access_op'] = array(
      '#type' => 'radios',
      '#title' => t('Access operation to check'),
      '#options' => array('view' => t('View'), 'edit' => t('Edit')),
      '#default_value' => $this->options['access_op'],
      '#dependency' => array('edit-options-validate-options-account-access' => array(TRUE)),
    );

    $form['aid_type'] = array(
      '#type' => 'select',
      '#title' => t('Filter value format'),
      '#options' => array(
        'aid' => t('Account ID'),
        'aids' => t('Account IDs separated by , or +'),
      ),
      '#default_value' => $this->options['aid_type'],
    );
  }

  function validate_argument($argument) {

    switch ($this->options['aid_type']) {
      case 'aid':
        if (!is_numeric($argument)) {
          return FALSE;
        }
        $account = ledger_account_load($argument);
        if (!$account) {
          return FALSE;
        }

        if (!empty($this->options['access'])) {
          if (!ledger_account_access($this->options['access_op'], $account)) {
            return FALSE;
          }
        }

        // Save the title() handlers some work.
        $this->argument->validated_title = check_plain($account->name);

        // Valid!
        return TRUE;

      case 'aids':
        $aids = new stdClass();
        $aids->value = array($argument);
        $aids = views_break_phrase($argument, $aids);
        if ($aids->value == array(-1)) {
          return FALSE;
        }

        $test = drupal_map_assoc($aids->value);
        $titles = array();

        $result = db_query("SELECT * FROM {ledger_account} WHERE aid IN (:aids)", array(':aids' =>  $aids->value));
        foreach ($result as $account) {

          if (!empty($this->options['access'])) {
            if (!ledger_account_access($this->options['access_op'], $account)) {
              return FALSE;
            }
          }

          $titles[] = check_plain($account->name);
          unset($test[$account->aid]);
        }

        $this->argument->validated_title = implode($aids->operator == 'or' ? ' + ' : ', ', $titles);
        // If this is not empty, we did not find a aid.
        return empty($test);
    }
  }
}
