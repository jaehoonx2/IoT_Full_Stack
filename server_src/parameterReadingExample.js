const express =  require('express')
const app = express()

app.get('/', (req, res) => res.send('Hello World!'))

var seq = 0;
app.get('/log', function(req,res) {
        console.log("%j", req.query)
        res.end(seq++)
})
// your_public_address:3000/public_api_key
app.listen(3000, () => console.log('Example app listening on port 3000!'))