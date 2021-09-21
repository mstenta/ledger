<?php

namespace Drupal\ledger_account\Form;

use Drupal\Core\Entity\BundleEntityFormBase;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Form handler for account type forms.
 */
class LedgerAccountTypeForm extends BundleEntityFormBase {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    $entity_type = $this->entity;
    if ($this->operation == 'add') {
      $form['#title'] = $this->t('Add account type');
    }
    else {
      $form['#title'] = $this->t(
        'Edit %label account type',
        ['%label' => $entity_type->label()]
      );
    }

    $form['label'] = [
      '#title' => $this->t('Label'),
      '#type' => 'textfield',
      '#default_value' => $entity_type->label(),
      '#description' => $this->t('The human-readable name of this account type.'),
      '#required' => TRUE,
      '#size' => 30,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $entity_type->id(),
      '#maxlength' => EntityTypeInterface::BUNDLE_MAX_LENGTH,
      '#machine_name' => [
        'exists' => ['Drupal\ledger_account\Entity\LedgerAccountType', 'load'],
        'source' => ['label'],
      ],
      '#description' => $this->t('A unique machine-readable name for this account type. It must only contain lowercase letters, numbers, and underscores.'),
    ];

    $form['type'] = [
      '#title' => $this->t('Fundamental type'),
      '#type' => 'select',
      '#default_value' => $entity_type->get('type'),
      '#options' => [
        'asset' => $this->t('Asset'),
        'equity' => $this->t('Equity'),
        'liability' => $this->t('Liability'),
        'income' => $this->t('Income'),
        'expense' => $this->t('Expense'),
      ],
      '#description' => $this->t('The fundamental bookkeeping account type. Must be one of: asset, equity, liability, income, or expense.'),
      '#required' => TRUE,
    ];

    return $this->protectBundleIdElement($form);
  }

  /**
   * {@inheritdoc}
   */
  protected function actions(array $form, FormStateInterface $form_state) {
    $actions = parent::actions($form, $form_state);
    $actions['submit']['#value'] = $this->t('Save account type');
    $actions['delete']['#value'] = $this->t('Delete account type');
    return $actions;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $entity_type = $this->entity;

    $entity_type->set('id', trim($entity_type->id()));
    $entity_type->set('label', trim($entity_type->label()));
    $entity_type->set('type', $entity_type->get('type'));

    $status = $entity_type->save();

    $t_args = ['%name' => $entity_type->label()];
    if ($status == SAVED_UPDATED) {
      $message = $this->t('The account type %name has been updated.', $t_args);
    }
    elseif ($status == SAVED_NEW) {
      $message = $this->t('The account type %name has been added.', $t_args);
    }
    $this->messenger()->addStatus($message);

    $form_state->setRedirectUrl($entity_type->toUrl('collection'));
  }

}
