## Blockchain in E-Commerce

The exchange handles bids, their creation (by the NM company), acceptance (by a supplier) and then the mutual agreement between the NM company and supplier (consensus), including the facilitation of the payment using a peso wallet.
After, the exchange can also handle retail orders involving 4 parties - the NM company (responsible for supplying the product), the courier (responsible for delivering the product), the distributor (who will receive compensation), and the retail customer (who is receiving and paying for the product).

Basically the flow between the NM company and the supplier is:

1. The NM company opens a bid with a certain product (e.g. 100 bottles of wine), certain reward (e.g. PHP 100,000.00), and a timeout. To do that, they need to lock PHP 100,000.00 to the smart contract
2. A supplier accepts this bid.
3. Every movement of the product is recorded on the blockchain (e.g. grapes harvested at this vineyard at this time, delivered to a winery at this time and in this amount etc.). There is incentive for each party involved to record the transaction because of instant compensation (i.e. deducted from the reward)
3. The supplier finally delivers the products to the NM company, and confirms that to the smart contract. The NM company also confirms this to the smart contract. This happens programatically, but the signing of the Ethereum transaction itself may need human intervention (e.g. if using a Trezor wallet)
4. The remaining PHP reward gets transferred to the supplier

Alternative scenarios are:

- The NM company cancels the bid before it's accepted, in which case the PHP gets returned
- The supplier gives up the bid after they've accepted it, in which case the PHP gets returned
