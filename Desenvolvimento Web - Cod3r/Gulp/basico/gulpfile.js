const gulp = require('gulp')
const { series, parallel } = require('gulp')

function antes1(cb) {
    console.log('Tarefa Antes 1.')
    return cb()
}

function antes2(cb) {
    console.log('Tarefa Antes 2.')
    return cb()
}

function copiar(cb) {
    // gulp.src(['pastaA/arquivo1.txt', 'pastaA/arquivo2.txt'])
    gulp.src('pastaA/**/*.txt')
        .pipe(gulp.dest('pastaB'))
    return cb()
}

function fim(cb) {
    console.log('Tarefa Fim.')
    return cb()
}

module.exports.default = series(
    parallel(antes1, antes2),
    copiar,
    fim
)