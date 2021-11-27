const {PriceGetter} = require('crypto-price-getter');
const fs = require('fs');

let fileName = 'Prices.json';
const toSearch = ['BTC', 'ETH', 'SOL', 'ADA', 'DOGE', 'MATIC', 'SHIB', 'LTC',]
let result = {};

let getPrice = async () => {
    result.detail = {};

    for(let i = 0; i < toSearch.length; i++){
        result.detail[toSearch[i]] = await PriceGetter.getLatestTradePrice(toSearch[i], "USD");
    }

    let now = new Date();

    result.lastUpdated = now.toString();
    fs.writeFile(fileName, JSON.stringify(result),  err =>  {
        if (err) return console.log(err);
    });

    console.log('updated | ' + now.toString());
}

getPrice();
setInterval(getPrice, 60000);