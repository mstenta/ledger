<?php

namespace Drupal\ledger_ledger;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;

/**
 * Defines the access control handler for the ledger entity type.
 */
class LedgerAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {

    switch ($operation) {
      case 'view':
        return AccessResult::allowedIfHasPermission($account, 'view ledger');

      case 'update':
        return AccessResult::allowedIfHasPermissions($account, ['edit ledger', 'administer ledger'], 'OR');

      case 'delete':
        return AccessResult::allowedIfHasPermissions($account, ['delete ledger', 'administer ledger'], 'OR');

      default:
        // No opinion.
        return AccessResult::neutral();
    }

  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermissions($account, ['create ledger', 'administer ledger'], 'OR');
  }

}
