<?php

namespace Drupal\ledger_account\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Form controller for Ledger Account edit forms.
 *
 * @ingroup ledger_account
 */
class LedgerAccountForm extends ContentEntityForm {

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    /* @var $entity \Drupal\ledger_account\Entity\LedgerAccount */
    $form = parent::buildForm($form, $form_state);
    $entity = $this->entity;

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $entity = $this->entity;
    $status = parent::save($form, $form_state);

    switch ($status) {
      case SAVED_NEW:
        drupal_set_message($this->t('Created the %label Ledger Account.', [
          '%label' => $entity->label(),
        ]));
        break;

      default:
        drupal_set_message($this->t('Saved the %label Ledger Account.', [
          '%label' => $entity->label(),
        ]));
    }
    $form_state->setRedirect('entity.ledger_account.canonical', ['ledger_account' => $entity->id()]);
  }

}
