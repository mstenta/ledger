<?php

namespace Drupal\ledger_account;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Ledger Account entity.
 *
 * @see \Drupal\ledger_account\Entity\LedgerAccount.
 */
class LedgerAccountAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\ledger_account\LedgerAccountInterface $entity */
    switch ($operation) {
      case 'view':
        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished ledger account entities');
        }
        return AccessResult::allowedIfHasPermission($account, 'view published ledger account entities');

      case 'update':
        return AccessResult::allowedIfHasPermission($account, 'edit ledger account entities');

      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete ledger account entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add ledger account entities');
  }

}
