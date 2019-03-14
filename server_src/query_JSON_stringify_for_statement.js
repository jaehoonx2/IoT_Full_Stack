const express = require('express')
const app = express()
const port = 3000

app.get('/log', function(req, res) {
    console.log("got request: "+ JSON.stringify(req.query))
    console.log(req.query.name)
    console.log(req.query.age)
    for (x in req.query)
        console.log(`key= ${x}, value=${req.query[x]}`)
    res.send('Hello World, Kim!'+ JSON.stringify(req.query))
})

app.listen(port, () => console.log(`Example app listening on port ${port}!`))