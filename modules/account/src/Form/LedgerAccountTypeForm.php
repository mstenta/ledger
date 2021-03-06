<?php

namespace Drupal\ledger_account\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Class LedgerAccountTypeForm.
 *
 * @package Drupal\ledger_account\Form
 */
class LedgerAccountTypeForm extends EntityForm {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    $ledger_account_type = $this->entity;
    $form['label'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Label'),
      '#maxlength' => 255,
      '#default_value' => $ledger_account_type->label(),
      '#description' => $this->t("Label for the Ledger Account type."),
      '#required' => TRUE,
    );

    $form['id'] = array(
      '#type' => 'machine_name',
      '#default_value' => $ledger_account_type->id(),
      '#machine_name' => array(
        'exists' => '\Drupal\ledger_account\Entity\LedgerAccountType::load',
      ),
      '#disabled' => !$ledger_account_type->isNew(),
    );

    $form['type'] = array(
      '#type' => 'select',
      '#title' => $this->t('Fundamental account type'),
      '#description' => $this->t('The fundamental type of account, used for reporting. If none is selected, accounts of this type will not be included in any reports.'),
      '#options' => array(
        'asset' => t('Asset'),
        'equity' => t('Equity'),
        'liability' => t('Liability'),
        'income' => t('Income'),
        'expense' => t('Expense'),
        'undefined' => t('undefined'),
      ),
      '#default_value' => $ledger_account_type->getType(),
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $ledger_account_type = $this->entity;
    $status = $ledger_account_type->save();

    switch ($status) {
      case SAVED_NEW:
        drupal_set_message($this->t('Created the %label Ledger Account type.', [
          '%label' => $ledger_account_type->label(),
        ]));
        break;

      default:
        drupal_set_message($this->t('Saved the %label Ledger Account type.', [
          '%label' => $ledger_account_type->label(),
        ]));
    }
    $form_state->setRedirectUrl($ledger_account_type->urlInfo('collection'));
  }

}
