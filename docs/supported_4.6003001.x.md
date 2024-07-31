# Polymesh 4.6003001.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |

## Babe

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Plan config change           |        |           |                  |         | `NextConfigDescriptor`config<br/>                                                      |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------------------ | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu64`now<br/> |

## Indices

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                               |
| -------------- | ------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------- |
| Claim          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex`index<br/>                                                |
| Transfer       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>                  |
| Free           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex`index<br/>                                                |
| Force transfer |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>`bool`freeze<br/> |
| Freeze         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex`index<br/>                                                |

## Balances

| Name                                 | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                               |
| ------------------------------------ | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------------------- |
| Transfer                             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource`dest<br/>`CompactBalance`amount<br/>                                        |
| Transfer with memo                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource`dest<br/>`CompactBalance`amount<br/>`OptionMemo`memo<br/>                   |
| Deposit block reward reserve balance |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                             |
| Set balance                          |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/>      |
| Force transfer                       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource`source<br/>`LookupasStaticLookupSource`dest<br/>`CompactBalance`amount<br/> |
| Burn account balance                 |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Balance`amount<br/>                                                                                    |

## Identity

| Name                                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                            |
| -------------------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------------------------------------------------------------- |
| Cdd register did                       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`target_account<br/>`VecSecondaryKeyAccountId`secondary_keys<br/>                          |
| Invalidate cdd claims                  |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`cdd<br/>`Moment`disable_from<br/>`OptionMoment`expiry<br/>                               |
| Accept primary key                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`rotation_auth_id<br/>`Optionu64`optional_cdd_auth_id<br/>                                       |
| Change cdd requirement for mk rotation |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`auth_required<br/>                                                                             |
| Join identity as key                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`auth_id<br/>                                                                                    |
| Leave identity as key                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                      |
| Add claim                              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`target<br/>`Claim`claim<br/>`OptionMoment`expiry<br/>                                    |
| Revoke claim                           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`target<br/>`Claim`claim<br/>                                                             |
| Freeze secondary keys                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                      |
| Unfreeze secondary keys                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                      |
| Add authorization                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SignatoryAccountId`target<br/>`AuthorizationDataAccountId`data<br/>`OptionMoment`expiry<br/>        |
| Remove authorization                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SignatoryAccountId`target<br/>`u64`auth_id<br/>`bool`\_auth_issuer_pays<br/>                        |
| Gc add cdd claim                       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`target<br/>                                                                              |
| Gc revoke cdd claim                    |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`target<br/>                                                                              |
| Revoke claim by index                  |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`target<br/>`ClaimType`claim_type<br/>`OptionScope`scope<br/>                             |
| Rotate primary key to secondary        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`auth_id<br/>`Optionu64`optional_cdd_auth_id<br/>                                                |
| Add secondary keys with authorization  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecSecondaryKeyWithAuthAccountId`additional_keys<br/>`Moment`expires_at<br/>                        |
| Set secondary key permissions          |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`key<br/>`Permissions`perms<br/>                                                           |
| Remove secondary keys                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`keys_to_remove<br/>                                                                    |
| Register custom claim type             |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`ty<br/>                                                                                       |
| Cdd register did with cdd              |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`target_account<br/>`VecSecondaryKeyAccountId`secondary_keys<br/>`OptionMoment`expiry<br/> |
| Create child identity                  |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`secondary_key<br/>                                                                        |
| Create child identities                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCreateChildIdentityWithAuthAccountId`child_keys<br/>`Moment`expires_at<br/>                      |
| Unlink child identity                  |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`child_did<br/>                                                                           |

## CddServiceProviders

| Name                     | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                          |
| ------------------------ | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------ |
| Set active members limit |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MemberCount`limit<br/>                                            |
| Disable member           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>`OptionMoment`expiry<br/>`OptionMoment`at<br/> |
| Add member               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Remove member            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Swap member              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`remove<br/>`IdentityId`add<br/>                        |
| Reset members            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecIdentityId`members<br/>                                        |
| Abdicate membership      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                    |

## PolymeshCommittee

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                      |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------- |
| Set vote threshold      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`n<br/>`u32`d<br/>                                         |
| Set release coordinator |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`id<br/>                                            |
| Set expires after       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlockBlockNumber`expiry<br/>                             |
| Vote or propose         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`approve<br/>`Proposal`call<br/>                          |
| Vote                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Hash`proposal<br/>`ProposalIndex`index<br/>`bool`approve<br/> |

## CommitteeMembership

| Name                     | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                          |
| ------------------------ | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------ |
| Set active members limit |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MemberCount`limit<br/>                                            |
| Disable member           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>`OptionMoment`expiry<br/>`OptionMoment`at<br/> |
| Add member               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Remove member            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Swap member              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`remove<br/>`IdentityId`add<br/>                        |
| Reset members            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecIdentityId`members<br/>                                        |
| Abdicate membership      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                    |

## TechnicalCommittee

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                      |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------- |
| Set vote threshold      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`n<br/>`u32`d<br/>                                         |
| Set release coordinator |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`id<br/>                                            |
| Set expires after       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlockBlockNumber`expiry<br/>                             |
| Vote or propose         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`approve<br/>`Proposal`call<br/>                          |
| Vote                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Hash`proposal<br/>`ProposalIndex`index<br/>`bool`approve<br/> |

## TechnicalCommitteeMembership

| Name                     | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                          |
| ------------------------ | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------ |
| Set active members limit |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MemberCount`limit<br/>                                            |
| Disable member           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>`OptionMoment`expiry<br/>`OptionMoment`at<br/> |
| Add member               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Remove member            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Swap member              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`remove<br/>`IdentityId`add<br/>                        |
| Reset members            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecIdentityId`members<br/>                                        |
| Abdicate membership      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                    |

## UpgradeCommittee

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                      |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------- |
| Set vote threshold      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`n<br/>`u32`d<br/>                                         |
| Set release coordinator |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`id<br/>                                            |
| Set expires after       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlockBlockNumber`expiry<br/>                             |
| Vote or propose         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`approve<br/>`Proposal`call<br/>                          |
| Vote                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Hash`proposal<br/>`ProposalIndex`index<br/>`bool`approve<br/> |

## UpgradeCommitteeMembership

| Name                     | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                          |
| ------------------------ | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------ |
| Set active members limit |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MemberCount`limit<br/>                                            |
| Disable member           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>`OptionMoment`expiry<br/>`OptionMoment`at<br/> |
| Add member               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Remove member            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`who<br/>                                               |
| Swap member              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`remove<br/>`IdentityId`add<br/>                        |
| Reset members            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecIdentityId`members<br/>                                        |
| Abdicate membership      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                    |

## MultiSig

| Name                                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                |
| -------------------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------- |
| Create multisig                        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecSignatoryAccountId`signers<br/>`u64`sigs_required<br/>                                               |
| Create or approve proposal as identity |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`Proposal`proposal<br/>`OptionMoment`expiry<br/>`bool`auto_close<br/>            |
| Create or approve proposal as key      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`Proposal`proposal<br/>`OptionMoment`expiry<br/>`bool`auto_close<br/>            |
| Create proposal as identity            |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`Proposal`proposal<br/>`OptionMoment`expiry<br/>`bool`auto_close<br/>            |
| Create proposal as key                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`Proposal`proposal<br/>`OptionMoment`expiry<br/>`bool`auto_close<br/>            |
| Approve as identity                    |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`u64`proposal_id<br/>                                                            |
| Approve as key                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`u64`proposal_id<br/>                                                            |
| Reject as identity                     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`u64`proposal_id<br/>                                                            |
| Reject as key                          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`u64`proposal_id<br/>                                                            |
| Accept multisig signer as identity     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`\_auth_id<br/>                                                                                      |
| Accept multisig signer as key          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`auth_id<br/>                                                                                        |
| Add multisig signer                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SignatoryAccountId`signer<br/>                                                                          |
| Remove multisig signer                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SignatoryAccountId`signer<br/>                                                                          |
| Add multisig signers via creator       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`VecSignatoryAccountId`signers<br/>                                              |
| Remove multisig signers via creator    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`VecSignatoryAccountId`signers<br/>                                              |
| Change sigs required                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`sigs_required<br/>                                                                                  |
| Make multisig secondary                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>                                                                                 |
| Make multisig primary                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`Optionu64`optional_cdd_auth_id<br/>                                             |
| Execute scheduled proposal             |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig<br/>`u64`proposal_id<br/>`IdentityId`multisig_did<br/>`Weight`\_proposal_weight<br/> |
| Change sigs required via creator       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig_account<br/>`u64`signatures_required<br/>                                            |
| Remove creator controls                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`multisig_account<br/>                                                                         |

## Bridge

| Name                       | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                      |
| -------------------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------- |
| Change controller          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`controller<br/>                     |
| Change admin               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`admin<br/>                          |
| Change timelock            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BlockNumber`timelock<br/>                     |
| Freeze                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                |
| Unfreeze                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                |
| Change bridge limit        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Balance`amount<br/>`BlockNumber`duration<br/> |
| Change bridge exempted     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecTupleIdentityIdbool`exempted<br/>          |
| Force handle bridge tx     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BridgeTxAccountId`bridge_tx<br/>              |
| Batch propose bridge tx    |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VecBridgeTxAccountId`bridge_txs<br/>          |
| Propose bridge tx          |        | :heavy_check_mark: | :heavy_check_mark: |                    | `BridgeTxAccountId`bridge_tx<br/>              |
| Handle bridge tx           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `BridgeTxAccountId`bridge_tx<br/>              |
| Freeze txs                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VecBridgeTxAccountId`bridge_txs<br/>          |
| Unfreeze txs               |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VecBridgeTxAccountId`bridge_txs<br/>          |
| Handle scheduled bridge tx |        | :heavy_check_mark: | :heavy_check_mark: |                    | `BridgeTxAccountId`bridge_tx<br/>              |
| Add freeze admin           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`freeze_admin<br/>                   |
| Remove freeze admin        |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`freeze_admin<br/>                   |
| Remove txs                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VecBridgeTxAccountId`bridge_txs<br/>          |

## Staking

| Name                                         | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                         |
| -------------------------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------- |
| Bond                                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`controller<br/>`CompactBalance`amount<br/>`RewardDestination`payee<br/>                                       |
| Bond extra                                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                       |
| Unbond                                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                       |
| Withdraw Unbonded                            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                      |
| Validate                                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs`prefs<br/>                                                                                                        |
| Nominate                                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                               |
| Chill                                        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                   |
| Set payee                                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                     |
| Set controller                               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`controller<br/>                                                                                               |
| Set validator count                          |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`new\_<br/>                                                                                                            |
| Increase validator count                     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`additional<br/>                                                                                                       |
| Scale validator count                        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Percent`factor<br/>                                                                                                              |
| Add permissioned validator                   |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`identity<br/>`Optionu32`intended_count<br/>                                                                           |
| Remove permissioned validator                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`identity<br/>                                                                                                         |
| Validate cdd expiry nominators               |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`targets<br/>                                                                                                        |
| Set commission cap                           |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Perbill`new_cap<br/>                                                                                                             |
| Set min bond threshold                       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Balance`new_value<br/>                                                                                                           |
| Force no eras                                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                   |
| Force new era                                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                   |
| Set invulnerables                            |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`invulnerables<br/>                                                                                                  |
| Force unstake                                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                 |
| Force new era always                         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                   |
| Cancel deferred slash                        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                      |
| Payout stakers                               |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                 |
| Rebond                                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                       |
| Set history depth                            |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`new_history_depth<br/>`Compactu32`era_items_deleted<br/>                                                              |
| Reap stash                                   |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                 |
| Submit election solution                     |                    |                    |                    |                    | `VecValidatorIndex`winners<br/>`CompactAssignments`compact<br/>`ElectionScore`score<br/>`EraIndex`era<br/>`ElectionSize`size<br/> |
| Submit election solution unsigned            |                    |                    |                    |                    | `VecValidatorIndex`winners<br/>`CompactAssignments`compact<br/>`ElectionScore`score<br/>`EraIndex`era<br/>`ElectionSize`size<br/> |
| Payout stakers by system                     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                 |
| Change slashing allowed for                  |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SlashingSwitch`slashing_switch<br/>                                                                                              |
| Update permissioned validator intended count |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`identity<br/>`u32`new_intended_count<br/>                                                                             |
| Chill from governance                        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`identity<br/>`VecAccountId`stash_keys<br/>                                                                            |

## Session

| Name       | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |                  |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |

## ImOnline

| Name      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| --------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Heartbeat |        |           |                  |         | `HeartbeatBlockNumber`heartbeat<br/>`AuthorityIdasRuntimeAppPublicSignature`signature<br/> |

## Asset

| Name                                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                              |
| ------------------------------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Register ticker                       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                                                                                                    |
| Accept ticker transfer                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`auth_id<br/>                                                                                                                                                      |
| Accept asset ownership transfer       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`auth_id<br/>                                                                                                                                                      |
| Create asset                          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AssetName`name<br/>`Ticker`ticker<br/>`bool`divisible<br/>`AssetType`asset_type<br/>`VecAssetIdentifier`identifiers<br/>`OptionFundingRoundName`funding_round<br/>    |
| Freeze                                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                                                                                                    |
| Unfreeze                              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                                                                                                    |
| Rename asset                          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`AssetName`name<br/>                                                                                                                                |
| Issue                                 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`BalanceNoSymbol`amount<br/>`PortfolioKind`portfolio_kind<br/>                                                                                      |
| Redeem                                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`BalanceNoSymbol`amount<br/>                                                                                                                        |
| Make divisible                        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                                                                                                    |
| Add documents                         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecDocument`docs<br/>`Ticker`ticker<br/>                                                                                                                              |
| Remove documents                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecDocumentId`ids<br/>`Ticker`ticker<br/>                                                                                                                             |
| Set funding round                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`FundingRoundName`name<br/>                                                                                                                         |
| Update identifiers                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`VecAssetIdentifier`asset_identifiers<br/>                                                                                                          |
| Controller transfer                   |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`BalanceNoSymbol`amount<br/>`PortfolioId`from_portfolio<br/>                                                                                        |
| Register custom asset type            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Vecu8`ty<br/>                                                                                                                                                         |
| Create asset with custom type         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AssetName`name<br/>`Ticker`ticker<br/>`bool`divisible<br/>`Vecu8`custom_asset_type<br/>`VecAssetIdentifier`identifiers<br/>`OptionFundingRoundName`funding_round<br/> |
| Set asset metadata                    |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataKey`key<br/>`AssetMetadataValue`value<br/>`OptionAssetMetadataValueDetailMoment`detail<br/>                                           |
| Set asset metadata details            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataKey`key<br/>`AssetMetadataValueDetailMoment`detail<br/>                                                                               |
| Register and set local asset metadata |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataName`name<br/>`AssetMetadataSpec`spec<br/>`AssetMetadataValue`value<br/>`OptionAssetMetadataValueDetailMoment`detail<br/>             |
| Register asset metadata local type    |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataName`name<br/>`AssetMetadataSpec`spec<br/>                                                                                            |
| Register asset metadata global type   |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AssetMetadataName`name<br/>`AssetMetadataSpec`spec<br/>                                                                                                               |
| Redeem from portfolio                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`BalanceNoSymbol`amount<br/>`PortfolioKind`portfolio<br/>                                                                                           |
| Update asset type                     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetType`asset_type<br/>                                                                                                                          |
| Remove local metadata key             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataLocalKey`local_key<br/>                                                                                                               |
| Remove metadata value                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`AssetMetadataKey`metadata_key<br/>                                                                                                                 |
| Exempt ticker affirmation             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>                                                                                                                                                    |
| Remove ticker affirmation exemption   |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>                                                                                                                                                    |
| Pre approve ticker                    |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>                                                                                                                                                    |
| Remove ticker pre approval            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>                                                                                                                                                    |
| Add mandatory mediators               |        |                    | :heavy_check_mark: |                    | `Ticker`ticker<br/>`BoundedBTreeSetIdentityIdMaxAssetMediators`mediators<br/>                                                                                          |
| Remove mandatory mediators            |        |                    | :heavy_check_mark: |                    | `Ticker`ticker<br/>`BoundedBTreeSetIdentityIdMaxAssetMediators`mediators<br/>                                                                                          |

## CapitalDistribution

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                 |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Distribute          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`OptionPortfolioNumber`portfolio<br/>`Ticker`currency<br/>`Balance`per_share<br/>`Balance`amount<br/>`Moment`payment_at<br/>`OptionMoment`expires_at<br/> |
| Claim               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>                                                                                                                                                          |
| Push benefit        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`IdentityId`holder<br/>                                                                                                                                   |
| Reclaim             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>                                                                                                                                                          |
| Remove distribution |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>                                                                                                                                                          |

## Checkpoint

| Name                         | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                             |
| ---------------------------- | ------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------- |
| Create checkpoint            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                   |
| Set schedules max complexity |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`max_complexity<br/>                              |
| Create schedule              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`ScheduleCheckpoints`schedule<br/> |
| Remove schedule              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`ScheduleId`id<br/>                |

## ComplianceManager

| Name                                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                     |
| ----------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------- |
| Add compliance requirement          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`VecCondition`sender_conditions<br/>`VecCondition`receiver_conditions<br/> |
| Remove compliance requirement       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`u32`id<br/>                                                               |
| Replace asset compliance            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`VecComplianceRequirement`asset_compliance<br/>                            |
| Reset asset compliance              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                           |
| Pause asset compliance              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                           |
| Resume asset compliance             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>                                                                           |
| Add default trusted claim issuer    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`TrustedIssuer`issuer<br/>                                                 |
| Remove default trusted claim issuer |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`IdentityId`issuer<br/>                                                    |
| Change compliance requirement       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`ComplianceRequirement`new_req<br/>                                        |

## CorporateAction

| Name                                     | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                           |
| ---------------------------------------- | ------ | --------- | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Set max details length                   |        |           | :heavy_check_mark: | :heavy_check_mark: | `u32`length<br/>                                                                                                                                                                                                                                    |
| Set default targets                      |        |           | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`TargetIdentities`targets<br/>                                                                                                                                                                                                   |
| Set default withholding tax              |        |           | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`Tax`tax<br/>                                                                                                                                                                                                                    |
| Set did withholding tax                  |        |           | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`IdentityId`taxed_did<br/>`OptionTax`tax<br/>                                                                                                                                                                                    |
| Initiate corporate action                |        |           | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`CAKind`kind<br/>`Moment`decl_date<br/>`OptionRecordDateSpec`record_date<br/>`CADetails`details<br/>`OptionTargetIdentities`targets<br/>`OptionTax`default_withholding_tax<br/>`OptionVecTupleIdentityIdTax`withholding_tax<br/> |
| Link ca doc                              |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`id<br/>`VecDocumentId`docs<br/>                                                                                                                                                                                                               |
| Remove ca                                |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>                                                                                                                                                                                                                                    |
| Change record date                       |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`OptionRecordDateSpec`record_date<br/>                                                                                                                                                                                              |
| Initiate corporate action and distribute |        |           | :heavy_check_mark: | :heavy_check_mark: | `InitiateCorporateActionArgs`ca_args<br/>`OptionPortfolioNumber`portfolio<br/>`Ticker`currency<br/>`Balance`per_share<br/>`Balance`amount<br/>`Moment`payment_at<br/>`OptionMoment`expires_at<br/>                                                  |

## CorporateBallot

| Name          | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting            | Arguments                                                                      |
| ------------- | ------ | --------- | ------------------ | ------------------ | ------------------------------------------------------------------------------ |
| Attach ballot |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`BallotTimeRange`range<br/>`BallotMeta`meta<br/>`bool`rcv<br/> |
| Vote          |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`VecBallotVote`votes<br/>                                      |
| Change end    |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`Moment`end<br/>                                               |
| Change meta   |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`BallotMeta`meta<br/>                                          |
| Change rcv    |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>`bool`rcv<br/>                                                 |
| Remove ballot |        |           | :heavy_check_mark: | :heavy_check_mark: | `CAId`ca_id<br/>                                                               |

## Pips

| Name                         | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                             |
| ---------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------- |
| Set prune historical pips    |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`prune<br/>                                                                                      |
| Set min proposal deposit     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Balance`deposit<br/>                                                                                 |
| Set default enactment period |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BlockNumber`duration<br/>                                                                            |
| Set pending pip expiry       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlockBlockNumber`expiry<br/>                                                                    |
| Set max pip skip count       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SkippedCount`max<br/>                                                                                |
| Set active pip limit         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`limit<br/>                                                                                       |
| Propose                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Proposal`proposal<br/>`Balance`deposit<br/>`OptionUrl`url<br/>`OptionPipDescription`description<br/> |
| Vote                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>`bool`aye_or_nay<br/>`Balance`deposit<br/>                                              |
| Approve committee proposal   |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>                                                                                        |
| Reject proposal              |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>                                                                                        |
| Prune proposal               |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>                                                                                        |
| Reschedule execution         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>`OptionBlockNumber`until<br/>                                                           |
| Clear snapshot               |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                       |
| Snapshot                     |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                       |
| Enact snapshot results       |                    |                    | :heavy_check_mark: | :heavy_check_mark: | `VecTuplePipIdSnapshotResult`results<br/>                                                             |
| Execute scheduled pip        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PipId`id<br/>                                                                                        |
| Expire scheduled pip         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `IdentityId`did<br/>`PipId`id<br/>                                                                    |

## Portfolio

| Name                                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                             |
| ----------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------- |
| Create portfolio                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PortfolioName`name<br/>                                              |
| Delete portfolio                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PortfolioNumber`num<br/>                                             |
| Rename portfolio                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PortfolioNumber`num<br/>`PortfolioName`to_name<br/>                  |
| Quit portfolio custody              |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PortfolioId`pid<br/>                                                 |
| Accept portfolio custody            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `u64`auth_id<br/>                                                     |
| Move portfolio funds                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PortfolioId`from<br/>`PortfolioId`to<br/>`VecFund`funds<br/>         |
| Pre approve portfolio               |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`PortfolioId`portfolio_id<br/>                     |
| Remove portfolio pre approval       |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Ticker`ticker<br/>`PortfolioId`portfolio_id<br/>                     |
| Allow identity to create portfolios |        |                    | :heavy_check_mark: |                    | `IdentityId`trusted_identity<br/>                                     |
| Revoke create portfolios permission |        |                    | :heavy_check_mark: |                    | `IdentityId`identity<br/>                                             |
| Create custody portfolio            |        |                    | :heavy_check_mark: |                    | `IdentityId`portfolio_owner_id<br/>`PortfolioName`portfolio_name<br/> |

## ProtocolFee

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                 |
| ------------------ | ------ | ------------------ | ------------------ | ------------------ | ----------------------------------------- |
| Change coefficient |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PosRatio`coefficient<br/>                |
| Change base fee    |        |                    |                    |                    | `ProtocolOp`op<br/>`Balance`base_fee<br/> |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Settlement

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                                                        |
| -------------------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create venue                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VenueDetails`details<br/>`VecAccountId`signers<br/>`VenueType`typ<br/>                                                                                                                                                                                                          |
| Update venue details             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VenueId`id<br/>`VenueDetails`details<br/>                                                                                                                                                                                                                                       |
| Update venue type                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VenueId`id<br/>`VenueType`typ<br/>                                                                                                                                                                                                                                              |
| Affirm with receipts             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `InstructionId`id<br/>`VecReceiptDetails`receipt_details<br/>`VecPortfolioId`portfolios<br/>                                                                                                                                                                                     |
| Set venue filtering              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`bool`enabled<br/>                                                                                                                                                                                                                                            |
| Allow venues                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`VecVenueId`venues<br/>                                                                                                                                                                                                                                       |
| Disallow venues                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Ticker`ticker<br/>`VecVenueId`venues<br/>                                                                                                                                                                                                                                       |
| Update venue signers             |        | :heavy_check_mark: | :heavy_check_mark: |                    | `VenueId`id<br/>`VecAccountId`signers<br/>`bool`add_signers<br/>                                                                                                                                                                                                                 |
| Execute manual instruction       |        | :heavy_check_mark: | :heavy_check_mark: |                    | `InstructionId`id<br/>`OptionPortfolioId`portfolio<br/>`u32`fungible_transfers<br/>`u32`nfts_transfers<br/>`u32`offchain_transfers<br/>`OptionWeight`weight_limit<br/>                                                                                                           |
| Add instruction                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VenueId`venue_id<br/>`SettlementTypeBlockNumber`settlement_type<br/>`OptionMoment`trade_date<br/>`OptionMoment`value_date<br/>`VecLeg`legs<br/>`OptionMemo`instruction_memo<br/>                                                                                                |
| Add and affirm instruction       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VenueId`venue_id<br/>`SettlementTypeBlockNumber`settlement_type<br/>`OptionMoment`trade_date<br/>`OptionMoment`value_date<br/>`VecLeg`legs<br/>`VecPortfolioId`portfolios<br/>`OptionMemo`instruction_memo<br/>                                                                 |
| Affirm instruction               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `InstructionId`id<br/>`VecPortfolioId`portfolios<br/>                                                                                                                                                                                                                            |
| Withdraw affirmation             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `InstructionId`id<br/>`VecPortfolioId`portfolios<br/>                                                                                                                                                                                                                            |
| Reject instruction               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `InstructionId`id<br/>`PortfolioId`portfolio<br/>                                                                                                                                                                                                                                |
| Execute scheduled instruction    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `InstructionId`id<br/>`Weight`weight_limit<br/>                                                                                                                                                                                                                                  |
| Affirm with receipts with count  |        |                    | :heavy_check_mark: |                    | `InstructionId`id<br/>`VecReceiptDetails`receipt_details<br/>`VecPortfolioId`portfolios<br/>`OptionAffirmationCount`number_of_assets<br/>                                                                                                                                        |
| Affirm instruction with count    |        |                    | :heavy_check_mark: |                    | `InstructionId`id<br/>`VecPortfolioId`portfolios<br/>`OptionAffirmationCount`number_of_assets<br/>                                                                                                                                                                               |
| Reject instruction with count    |        |                    | :heavy_check_mark: |                    | `InstructionId`id<br/>`PortfolioId`portfolio<br/>`OptionAssetCount`number_of_assets<br/>                                                                                                                                                                                         |
| Withdraw affirmation with count  |        |                    | :heavy_check_mark: |                    | `InstructionId`id<br/>`VecPortfolioId`portfolios<br/>`OptionAffirmationCount`number_of_assets<br/>                                                                                                                                                                               |
| Add instruction with mediators   |        |                    | :heavy_check_mark: |                    | `VenueId`venue_id<br/>`SettlementTypeBlockNumber`settlement_type<br/>`OptionMoment`trade_date<br/>`OptionMoment`value_date<br/>`VecLeg`legs<br/>`OptionMemo`instruction_memo<br/>`BoundedBTreeSetIdentityIdMaxInstructionMediators`mediators<br/>                                |
| Add and affirm with mediators    |        |                    | :heavy_check_mark: |                    | `VenueId`venue_id<br/>`SettlementTypeBlockNumber`settlement_type<br/>`OptionMoment`trade_date<br/>`OptionMoment`value_date<br/>`VecLeg`legs<br/>`VecPortfolioId`portfolios<br/>`OptionMemo`instruction_memo<br/>`BoundedBTreeSetIdentityIdMaxInstructionMediators`mediators<br/> |
| Affirm instruction as mediator   |        |                    | :heavy_check_mark: |                    | `InstructionId`instruction_id<br/>`OptionMoment`expiry<br/>                                                                                                                                                                                                                      |
| Withdraw affirmation as mediator |        |                    | :heavy_check_mark: |                    | `InstructionId`instruction_id<br/>                                                                                                                                                                                                                                               |
| Reject instruction as mediator   |        |                    | :heavy_check_mark: |                    | `InstructionId`instruction_id<br/>`OptionAssetCount`number_of_assets<br/>                                                                                                                                                                                                        |

## Statistics

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                        |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------ |
| Set active asset stats        |        |           |                  |         | `AssetScope`asset<br/>`BTreeSetStatType`stat_types<br/>                                          |
| Batch update asset stats      |        |           |                  |         | `AssetScope`asset<br/>`StatType`stat_type<br/>`BTreeSetStatUpdate`values<br/>                    |
| Set asset transfer compliance |        |           |                  |         | `AssetScope`asset<br/>`BTreeSetTransferCondition`transfer_conditions<br/>                        |
| Set entities exempt           |        |           |                  |         | `bool`is_exempt<br/>`TransferConditionExemptKey`exempt_key<br/>`BTreeSetIdentityId`entities<br/> |

## Sto

| Name                     | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                                                                                                            |
| ------------------------ | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create fundraiser        |        | :heavy_check_mark: | :heavy_check_mark: |         | `PortfolioId`offering_portfolio<br/>`Ticker`offering_asset<br/>`PortfolioId`raising_portfolio<br/>`Ticker`raising_asset<br/>`VecPriceTier`tiers<br/>`VenueId`venue_id<br/>`OptionMoment`start<br/>`OptionMoment`end<br/>`BalanceNoSymbol`minimum_investment<br/>`FundraiserName`fundraiser_name<br/> |
| Invest                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `PortfolioId`investment_portfolio<br/>`PortfolioId`funding_portfolio<br/>`Ticker`offering_asset<br/>`FundraiserId`id<br/>`BalanceNoSymbol`purchase_amount<br/>`OptionBalance`max_price<br/>`OptionReceiptDetails`receipt<br/>                                                                        |
| Freeze fundraiser        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`offering_asset<br/>`FundraiserId`id<br/>                                                                                                                                                                                                                                                     |
| Unfreeze fundraiser      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`offering_asset<br/>`FundraiserId`id<br/>                                                                                                                                                                                                                                                     |
| Modify fundraiser window |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`offering_asset<br/>`FundraiserId`id<br/>`Moment`start<br/>`OptionMoment`end<br/>                                                                                                                                                                                                             |
| Stop                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`offering_asset<br/>`FundraiserId`id<br/>                                                                                                                                                                                                                                                     |

## Treasury

| Name          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                          |
| ------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------------- |
| Disbursement  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecBeneficiary`beneficiaries<br/> |
| Reimbursement |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Balance`amount<br/>               |

## Utility

| Name             | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                    |
| ---------------- | ------------------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------------------------------------- |
| Batch            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCall`calls<br/>                                                          |
| Relay tx         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`target<br/>`OffChainSignature`signature<br/>`UniqueCall`call<br/> |
| Batch all        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecCall`calls<br/>                                                          |
| Dispatch as      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/>                              |
| Force batch      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecCall`calls<br/>                                                          |
| With weight      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Call`call<br/>`Weight`weight<br/>                                           |
| Batch old        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecCall`calls<br/>                                                          |
| Batch atomic     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCall`calls<br/>                                                          |
| Batch optimistic | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCall`calls<br/>                                                          |
| As derivative    |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `u16`index<br/>`Call`call<br/>                                               |

## Base

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## ExternalAgents

| Name                           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                           |
| ------------------------------ | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------- |
| Create group                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`ExtrinsicPermissions`perms<br/>                                                 |
| Set group permissions          |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`AGId`id<br/>`ExtrinsicPermissions`perms<br/>                                    |
| Remove agent                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`IdentityId`agent<br/>                                                           |
| Abdicate                       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>                                                                                 |
| Change group                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`IdentityId`agent<br/>`AgentGroup`group<br/>                                     |
| Accept become agent            |        | :heavy_check_mark: | :heavy_check_mark: |         | `u64`auth_id<br/>                                                                                   |
| Create group and add auth      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`ExtrinsicPermissions`perms<br/>`IdentityId`target<br/>`OptionMoment`expiry<br/> |
| Create and change custom group |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`ExtrinsicPermissions`perms<br/>`IdentityId`agent<br/>                           |

## Relayer

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                          |
| -------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------- |
| Set paying key       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`user_key<br/>`Balance`polyx_limit<br/>  |
| Accept paying key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u64`auth_id<br/>                                  |
| Remove paying key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`user_key<br/>`AccountId`paying_key<br/> |
| Update polyx limit   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`user_key<br/>`Balance`polyx_limit<br/>  |
| Increase polyx limit |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`user_key<br/>`Balance`amount<br/>       |
| Decrease polyx limit |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`user_key<br/>`Balance`amount<br/>       |

## Contracts

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                       |
| -------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call old weight                  |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`data<br/>            |
| Instantiate with code old weight |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`code<br/>`Bytes`data<br/>`Bytes`salt<br/>         |
| Instantiate old weight           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/> |
| Upload code                      |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Bytes`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Determinism`determinism<br/>                                                                 |
| Remove code                      |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code                         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
| Call                             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`data<br/>                |
| Instantiate with code            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`code<br/>`Bytes`data<br/>`Bytes`salt<br/>             |
| Instantiate                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/>     |

## PolymeshContracts

| Name                                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                             |
| ------------------------------------ | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Instantiate with code perms          |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`endowment<br/>`Weight`gas_limit<br/>`OptionBalance`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>`Permissions`perms<br/>         |
| Instantiate with hash perms          |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`endowment<br/>`Weight`gas_limit<br/>`OptionBalance`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Vecu8`data<br/>`Vecu8`salt<br/>`Permissions`perms<br/> |
| Update call runtime whitelist        |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecTupleExtrinsicIdbool`updates<br/>                                                                                                                                 |
| Instantiate with code as primary key |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`endowment<br/>`Weight`gas_limit<br/>`OptionBalance`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>                                |
| Instantiate with hash as primary key |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`endowment<br/>`Weight`gas_limit<br/>`OptionBalance`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Vecu8`data<br/>`Vecu8`salt<br/>                        |
| Upgrade api                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `Api`api<br/>`NextUpgradeT`next_upgrade<br/>                                                                                                                          |

## Preimage

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments         |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ----------------- |
| Note preimage      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Request preimage   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Unrequest preimage |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |

## Nft

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                      |
| --------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------------------------------------------- |
| Create nft collection |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`OptionNonFungibleType`nft_type<br/>`VecAssetMetadataKey`collection_keys<br/>               |
| Issue nft             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`VecNFTMetadataAttribute`nft_metadata_attributes<br/>`PortfolioKind`portfolio_kind<br/>     |
| Redeem nft            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Ticker`ticker<br/>`NFTId`nft_id<br/>`PortfolioKind`portfolio_kind<br/>                                        |
| Controller transfer   |        |                    | :heavy_check_mark: |         | `Ticker`ticker<br/>`NFTs`nfts<br/>`PortfolioId`source_portfolio<br/>`PortfolioKind`callers_portfolio_kind<br/> |

## StateTrieMigration

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Control auto migration |        |           |                  |         | `OptionMigrationLimits`maybe_config<br/>                                               |
| Continue migrate       |        |           |                  |         | `MigrationLimits`limits<br/>`u32`real_size_upper<br/>`MigrationTaskT`witness_task<br/> |
| Migrate custom top     |        |           |                  |         | `VecVecu8`keys<br/>`u32`witness_size<br/>                                              |
| Migrate custom child   |        |           |                  |         | `Vecu8`root<br/>`VecVecu8`child_keys<br/>`u32`total_size<br/>                          |
| Set signed max limits  |        |           |                  |         | `MigrationLimits`limits<br/>                                                           |
| Force set progress     |        |           |                  |         | `ProgressOfT`progress_top<br/>`ProgressOfT`progress_child<br/>                         |
