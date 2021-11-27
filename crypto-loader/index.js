const {PriceGetter} = require('crypto-price-getter');

const toSearch = ['BTC', 'ETH', 'SOL', 'ADA', 'DOGE', 'MATIC', 'SHIB', 'LTC',]
let result = {};

let getPrice = async () => {
    for(let i = 0; i < toSearch.length; i++){
        result.detail[toSearch[i]] = await PriceGetter.getLatestTradePrice(toSearch[i], "USD");
    }

    let now = new Date();

    result.detail = JSON.stringify(result);

    console.log('updated | ' + now.toString());
}

getPrice();
setInterval(getPrice, 60000);