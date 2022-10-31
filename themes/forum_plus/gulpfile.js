/**
 * @file
 * Instructions for the gulp streaming build system.
 */

// Dependencies.
const gulp = require("gulp");
const sass = require('gulp-sass')(require('sass'));
const sourcemaps = require("gulp-sourcemaps");
const autoprefixer = require("gulp-autoprefixer");

// Configuration variables.
const config = {
  input: "./sass/**/*.scss",
  output: "./css",
  sassOptions: {
    outputStyle: "expanded"
  },
  autoprefixerOptions: {
    // Match upstream Bootstrap's level of browser compatibility.
    // See: https://github.com/twbs/bootstrap-sass#sass-autoprefixer
    overrideBrowserslist: [
      "Android 2.3",
      "Android >= 4",
      "Chrome >= 20",
      "Firefox >= 24",
      "Explorer >= 8",
      "iOS >= 6",
      "Opera >= 12",
      "Safari >= 6"
    ]
  }
};

/**
 * Sass compilation task for development environments.
 */
gulp.task("sass", () =>
  gulp
    .src(config.input)
    .pipe(sourcemaps.init())
    .pipe(sass(config.sassOptions).on("error", sass.logError))
    .pipe(autoprefixer(config.autoprefixerOptions))
    .pipe(sourcemaps.write())
    .pipe(gulp.dest(config.output))
);

/**
 * Watcher task.
 */
gulp.task("watch", () => gulp.watch(config.input, gulp.series("sass")));

/**
 * Default gulp task.
 */
gulp.task("default", gulp.series("sass", "watch"));

/**
 * Production build task.
 */
gulp.task("prod", () => {
  config.sassOptions.outputStyle = "compressed";
  return gulp
    .src(config.input)
    .pipe(sass(config.sassOptions))
    .pipe(autoprefixer(config.autoprefixerOptions))
    .pipe(gulp.dest(config.output));
});
