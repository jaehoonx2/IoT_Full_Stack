const express = require('express')
const fs = require("fs")
const app = express()
const port = 3000

app.get('/log', function(req, res) {
    console.log("got request: "+ JSON.stringify(req.query))
    console.log(req.query.name)
    console.log(req.query.age)
    for (x in req.query)
        console.log(`key= ${x}, value=${req.query[x]}`)
    fs.appendFile('data.log', JSON.stringify(req.query)+'\n', function (err) {
        if (err) throw err;
        console.log(`got ${JSON.stringify(req.query)}`)
    });
    res.send('OK '+ JSON.stringify(req.query))
})

app.listen(port, () => console.log(`Example app listening on port ${port}!`))