const express = require('express')
const app = express()
const port = 3000

app.get('/log', function(req, res) {
    console.log("got request: "+ JSON.stringify(req.query))
    console.log(req.query.name)
    console.log(req.query.age)
    res.send('Hello World'+ JSON.stringify(req.query))
})

app.listen(port, () => console.log(`Example app listening on port ${port}!`))